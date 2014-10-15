// Copyright (c) 2011-2014 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GAPCOINADDRESSVALIDATOR_H
#define GAPCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class GapcoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GapcoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Gapcoin address widget validator, checks for a valid gapcoin address.
 */
class GapcoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit GapcoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // GAPCOINADDRESSVALIDATOR_H
