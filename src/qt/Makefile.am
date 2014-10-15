include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = gapcoin-qt
noinst_LIBRARIES = libgapcoinqt.a
SUBDIRS = . $(BUILD_TEST_QT)
DIST_SUBDIRS = . test

# gapcoin qt core #
QT_TS = \
  locale/gapcoin_ach.ts \
  locale/gapcoin_af_ZA.ts \
  locale/gapcoin_ar.ts \
  locale/gapcoin_be_BY.ts \
  locale/gapcoin_bg.ts \
  locale/gapcoin_bs.ts \
  locale/gapcoin_ca_ES.ts \
  locale/gapcoin_ca.ts \
  locale/gapcoin_ca@valencia.ts \
  locale/gapcoin_cmn.ts \
  locale/gapcoin_cs.ts \
  locale/gapcoin_cy.ts \
  locale/gapcoin_da.ts \
  locale/gapcoin_de.ts \
  locale/gapcoin_el_GR.ts \
  locale/gapcoin_en.ts \
  locale/gapcoin_eo.ts \
  locale/gapcoin_es_CL.ts \
  locale/gapcoin_es_DO.ts \
  locale/gapcoin_es_MX.ts \
  locale/gapcoin_es.ts \
  locale/gapcoin_es_UY.ts \
  locale/gapcoin_et.ts \
  locale/gapcoin_eu_ES.ts \
  locale/gapcoin_fa_IR.ts \
  locale/gapcoin_fa.ts \
  locale/gapcoin_fi.ts \
  locale/gapcoin_fr_CA.ts \
  locale/gapcoin_fr.ts \
  locale/gapcoin_gl.ts \
  locale/gapcoin_gu_IN.ts \
  locale/gapcoin_he.ts \
  locale/gapcoin_hi_IN.ts \
  locale/gapcoin_hr.ts \
  locale/gapcoin_hu.ts \
  locale/gapcoin_id_ID.ts \
  locale/gapcoin_it.ts \
  locale/gapcoin_ja.ts \
  locale/gapcoin_ka.ts \
  locale/gapcoin_kk_KZ.ts \
  locale/gapcoin_ko_KR.ts \
  locale/gapcoin_ky.ts \
  locale/gapcoin_la.ts \
  locale/gapcoin_lt.ts \
  locale/gapcoin_lv_LV.ts \
  locale/gapcoin_mn.ts \
  locale/gapcoin_ms_MY.ts \
  locale/gapcoin_nb.ts \
  locale/gapcoin_nl.ts \
  locale/gapcoin_pam.ts \
  locale/gapcoin_pl.ts \
  locale/gapcoin_pt_BR.ts \
  locale/gapcoin_pt_PT.ts \
  locale/gapcoin_ro_RO.ts \
  locale/gapcoin_ru.ts \
  locale/gapcoin_sah.ts \
  locale/gapcoin_sk.ts \
  locale/gapcoin_sl_SI.ts \
  locale/gapcoin_sq.ts \
  locale/gapcoin_sr.ts \
  locale/gapcoin_sv.ts \
  locale/gapcoin_th_TH.ts \
  locale/gapcoin_tr.ts \
  locale/gapcoin_uk.ts \
  locale/gapcoin_ur_PK.ts \
  locale/gapcoin_uz@Cyrl.ts \
  locale/gapcoin_vi.ts \
  locale/gapcoin_vi_VN.ts \
  locale/gapcoin_zh_CN.ts \
  locale/gapcoin_zh_HK.ts \
  locale/gapcoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_gapcoinaddressvalidator.cpp \
  moc_gapcoinamountfield.cpp \
  moc_gapcoingui.cpp \
  moc_gapcoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

GAPCOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  gapcoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_gapcoin.cpp
QT_QRC = gapcoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

GAPCOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  gapcoinaddressvalidator.h \
  gapcoinamountfield.h \
  gapcoingui.h \
  gapcoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h \
  winshutdownmonitor.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/gapcoin.ico \
  res/icons/gapcoin.png \
  res/icons/gapcoin_testnet.ico \
  res/icons/gapcoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

GAPCOIN_QT_CPP = \
  gapcoin.cpp \
  gapcoinaddressvalidator.cpp \
  gapcoinamountfield.cpp \
  gapcoingui.cpp \
  gapcoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp \
  winshutdownmonitor.cpp

if ENABLE_WALLET
GAPCOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  signverifymessagedialog.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

GAPCOIN_RC = res/gapcoin-qt-res.rc

libgapcoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libgapcoinqt_a_SOURCES = $(GAPCOIN_QT_CPP) $(GAPCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libgapcoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libgapcoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# gapcoin-qt binary #
gapcoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
gapcoin_qt_SOURCES = gapcoin.cpp
if TARGET_DARWIN
  gapcoin_qt_SOURCES += $(GAPCOIN_MM)
endif
if TARGET_WINDOWS
  gapcoin_qt_SOURCES += $(GAPCOIN_RC)
endif
gapcoin_qt_LDADD = libgapcoinqt.a $(LIBGAPCOIN_SERVER)
if ENABLE_WALLET
gapcoin_qt_LDADD += $(LIBGAPCOIN_WALLET)
endif
gapcoin_qt_LDADD += $(LIBGAPCOIN_CLI) $(LIBGAPCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
gapcoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

gapcoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/gapcoinstrings.cpp

translate: gapcoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(GAPCOIN_QT_CPP) $(GAPCOIN_QT_H) $(GAPCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/gapcoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name gapcoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -e '/^\*\*.*Created:/d' $@ > $@.n && mv $@{.n,}
	$(SED) -e '/^\*\*.*by:/d' $@  > $@.n && mv $@{.n,}

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
