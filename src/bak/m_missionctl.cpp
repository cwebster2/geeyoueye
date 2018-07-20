/****************************************************************************
** MainWindow meta object code from reading C++ file 'missionctl.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "missionctl.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainWindow::className() const
{
    return "MainWindow";
}

QMetaObject *MainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainWindow;

#ifndef QT_NO_TRANSLATION
QString MainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"sendPacket", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"sendPacket", 3, param_slot_1 };
    static const QUMethod slot_2 = {"startconnect", 0, 0 };
    static const QUMethod slot_3 = {"endconnect", 0, 0 };
    static const QUMethod slot_4 = {"hostdone", 0, 0 };
    static const QUMethod slot_5 = {"hostconnect", 0, 0 };
    static const QUMethod slot_6 = {"sigcon", 0, 0 };
    static const QUMethod slot_7 = {"toggletel", 0, 0 };
    static const QUMethod slot_8 = {"togglevel", 0, 0 };
    static const QUMethod slot_9 = {"toggleTweak", 0, 0 };
    static const QUMethod slot_10 = {"toggleDebug", 0, 0 };
    static const QUMethod slot_11 = {"toggleWatch", 0, 0 };
    static const QUMethod slot_12 = {"toggleAP", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"setStat1", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"setStat2", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"setapstat", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"setgpstat", 1, param_slot_16 };
    static const QUMethod slot_17 = {"setQWS", 0, 0 };
    static const QUMethod slot_18 = {"setQSGIW", 0, 0 };
    static const QUMethod slot_19 = {"setQCDEW", 0, 0 };
    static const QUMethod slot_20 = {"setQMW", 0, 0 };
    static const QUMethod slot_21 = {"setQMPW", 0, 0 };
    static const QUMethod slot_22 = {"setQPW", 0, 0 };
    static const QUMethod slot_23 = {"about", 0, 0 };
    static const QUMethod slot_24 = {"aboutqt", 0, 0 };
    static const QUMethod slot_25 = {"thptstats", 0, 0 };
    static const QUMethod slot_26 = {"picformats", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "sendPacket(int)", &slot_0, QMetaData::Public },
	{ "sendPacket(int,const char*,int)", &slot_1, QMetaData::Public },
	{ "startconnect()", &slot_2, QMetaData::Public },
	{ "endconnect()", &slot_3, QMetaData::Public },
	{ "hostdone()", &slot_4, QMetaData::Public },
	{ "hostconnect()", &slot_5, QMetaData::Public },
	{ "sigcon()", &slot_6, QMetaData::Public },
	{ "toggletel()", &slot_7, QMetaData::Public },
	{ "togglevel()", &slot_8, QMetaData::Public },
	{ "toggleTweak()", &slot_9, QMetaData::Public },
	{ "toggleDebug()", &slot_10, QMetaData::Public },
	{ "toggleWatch()", &slot_11, QMetaData::Public },
	{ "toggleAP()", &slot_12, QMetaData::Public },
	{ "setStat1(QString)", &slot_13, QMetaData::Public },
	{ "setStat2(QString)", &slot_14, QMetaData::Public },
	{ "setapstat(QString)", &slot_15, QMetaData::Public },
	{ "setgpstat(QString)", &slot_16, QMetaData::Public },
	{ "setQWS()", &slot_17, QMetaData::Public },
	{ "setQSGIW()", &slot_18, QMetaData::Public },
	{ "setQCDEW()", &slot_19, QMetaData::Public },
	{ "setQMW()", &slot_20, QMetaData::Public },
	{ "setQMPW()", &slot_21, QMetaData::Public },
	{ "setQPW()", &slot_22, QMetaData::Public },
	{ "about()", &slot_23, QMetaData::Public },
	{ "aboutqt()", &slot_24, QMetaData::Public },
	{ "thptstats()", &slot_25, QMetaData::Public },
	{ "picformats()", &slot_26, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainWindow", parentObject,
	slot_tbl, 27,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* MainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainWindow" ) ) return (MainWindow*)this;
    return QMainWindow::qt_cast( clname );
}

bool MainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: sendPacket(static_QUType_int.get(_o+1)); break;
    case 1: sendPacket(static_QUType_int.get(_o+1),static_QUType_charstar.get(_o+2),static_QUType_int.get(_o+3)); break;
    case 2: startconnect(); break;
    case 3: endconnect(); break;
    case 4: hostdone(); break;
    case 5: hostconnect(); break;
    case 6: sigcon(); break;
    case 7: toggletel(); break;
    case 8: togglevel(); break;
    case 9: toggleTweak(); break;
    case 10: toggleDebug(); break;
    case 11: toggleWatch(); break;
    case 12: toggleAP(); break;
    case 13: setStat1(static_QUType_QString.get(_o+1)); break;
    case 14: setStat2(static_QUType_QString.get(_o+1)); break;
    case 15: setapstat(static_QUType_QString.get(_o+1)); break;
    case 16: setgpstat(static_QUType_QString.get(_o+1)); break;
    case 17: setQWS(); break;
    case 18: setQSGIW(); break;
    case 19: setQCDEW(); break;
    case 20: setQMW(); break;
    case 21: setQMPW(); break;
    case 22: setQPW(); break;
    case 23: about(); break;
    case 24: aboutqt(); break;
    case 25: thptstats(); break;
    case 26: picformats(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QMainWindow::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
