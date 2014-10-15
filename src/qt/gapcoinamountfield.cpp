// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "gapcoinamountfield.h"

#include "gapcoinunits.h"
#include "guiconstants.h"
#include "qvaluecombobox.h"

#include <QApplication>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <qmath.h> // for qPow()

GapcoinAmountField::GapcoinAmountField(QWidget *parent) :
    QWidget(parent),
    amount(0),
    currentUnit(-1)
{
    nSingleStep = 100000; // satoshis

    amount = new QDoubleSpinBox(this);
    amount->setLocale(QLocale::c());
    amount->installEventFilter(this);
    amount->setMaximumWidth(170);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(amount);
    unit = new QValueComboBox(this);
    unit->setModel(new GapcoinUnits(this));
    layout->addWidget(unit);
    layout->addStretch(1);
    layout->setContentsMargins(0,0,0,0);

    setLayout(layout);

    setFocusPolicy(Qt::TabFocus);
    setFocusProxy(amount);

    // If one if the widgets changes, the combined content changes as well
    connect(amount, SIGNAL(valueChanged(QString)), this, SIGNAL(textChanged()));
    connect(unit, SIGNAL(currentIndexChanged(int)), this, SLOT(unitChanged(int)));

    // Set default based on configuration
    unitChanged(unit->currentIndex());
}

void GapcoinAmountField::setText(const QString &text)
{
    if (text.isEmpty())
        amount->clear();
    else
        amount->setValue(text.toDouble());
}

void GapcoinAmountField::clear()
{
    amount->clear();
    unit->setCurrentIndex(0);
}

bool GapcoinAmountField::validate()
{
    bool valid = true;
    if (amount->value() == 0.0)
        valid = false;
    else if (!GapcoinUnits::parse(currentUnit, text(), 0))
        valid = false;
    else if (amount->value() > GapcoinUnits::maxAmount(currentUnit))
        valid = false;

    setValid(valid);

    return valid;
}

void GapcoinAmountField::setValid(bool valid)
{
    if (valid)
        amount->setStyleSheet("");
    else
        amount->setStyleSheet(STYLE_INVALID);
}

QString GapcoinAmountField::text() const
{
    if (amount->text().isEmpty())
        return QString();
    else
        return amount->text();
}

bool GapcoinAmountField::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        // Clear invalid flag on focus
        setValid(true);
    }
    else if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Comma)
        {
            // Translate a comma into a period
            QKeyEvent periodKeyEvent(event->type(), Qt::Key_Period, keyEvent->modifiers(), ".", keyEvent->isAutoRepeat(), keyEvent->count());
            QApplication::sendEvent(object, &periodKeyEvent);
            return true;
        }
    }
    return QWidget::eventFilter(object, event);
}

QWidget *GapcoinAmountField::setupTabChain(QWidget *prev)
{
    QWidget::setTabOrder(prev, amount);
    QWidget::setTabOrder(amount, unit);
    return unit;
}

qint64 GapcoinAmountField::value(bool *valid_out) const
{
    qint64 val_out = 0;
    bool valid = GapcoinUnits::parse(currentUnit, text(), &val_out);
    if (valid_out)
    {
        *valid_out = valid;
    }
    return val_out;
}

void GapcoinAmountField::setValue(qint64 value)
{
    setText(GapcoinUnits::format(currentUnit, value));
}

void GapcoinAmountField::setReadOnly(bool fReadOnly)
{
    amount->setReadOnly(fReadOnly);
    unit->setEnabled(!fReadOnly);
}

void GapcoinAmountField::unitChanged(int idx)
{
    // Use description tooltip for current unit for the combobox
    unit->setToolTip(unit->itemData(idx, Qt::ToolTipRole).toString());

    // Determine new unit ID
    int newUnit = unit->itemData(idx, GapcoinUnits::UnitRole).toInt();

    // Parse current value and convert to new unit
    bool valid = false;
    qint64 currentValue = value(&valid);

    currentUnit = newUnit;

    // Set max length after retrieving the value, to prevent truncation
    amount->setDecimals(GapcoinUnits::decimals(currentUnit));
    amount->setMaximum(qPow(10, GapcoinUnits::amountDigits(currentUnit)) - qPow(10, -amount->decimals()));
    amount->setSingleStep((double)nSingleStep / (double)GapcoinUnits::factor(currentUnit));

    if (valid)
    {
        // If value was valid, re-place it in the widget with the new unit
        setValue(currentValue);
    }
    else
    {
        // If current value is invalid, just clear field
        setText("");
    }
    setValid(true);
}

void GapcoinAmountField::setDisplayUnit(int newUnit)
{
    unit->setValue(newUnit);
}

void GapcoinAmountField::setSingleStep(qint64 step)
{
    nSingleStep = step;
    unitChanged(unit->currentIndex());
}
