/****************************************************************************
** TweakWidget meta object code from reading C++ file 'tweak.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "tweak.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TweakWidget::className() const
{
    return "TweakWidget";
}

QMetaObject *TweakWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TweakWidget;

#ifndef QT_NO_TRANSLATION
QString TweakWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TweakWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TweakWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TweakWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TweakWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"newValue", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "pidval", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setAll", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "newValue()", &slot_0, QMetaData::Public },
	{ "setAll(pidval)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TweakWidget", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TweakWidget.setMetaObject( metaObj );
    return metaObj;
}

void* TweakWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TweakWidget" ) ) return (TweakWidget*)this;
    return QWidget::qt_cast( clname );
}

bool TweakWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newValue(); break;
    case 1: setAll(*((pidval*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TweakWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TweakWidget::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES


const char *TweakWindow::className() const
{
    return "TweakWindow";
}

QMetaObject *TweakWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TweakWindow;

#ifndef QT_NO_TRANSLATION
QString TweakWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TweakWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TweakWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TweakWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TweakWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"newDataAvailable", 1, param_slot_0 };
    static const QUMethod slot_1 = {"goPressed", 0, 0 };
    static const QUMethod slot_2 = {"countdown", 0, 0 };
    static const QUMethod slot_3 = {"newButton", 0, 0 };
    static const QUMethod slot_4 = {"resetButton", 0, 0 };
    static const QUMethod slot_5 = {"loadButton", 0, 0 };
    static const QUMethod slot_6 = {"sendButton", 0, 0 };
    static const QUMethod slot_7 = {"saveState", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"loadSet", 1, param_slot_8 };
    static const QUMethod slot_9 = {"newSet", 0, 0 };
    static const QUMethod slot_10 = {"changeMode", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "newDataAvailable(int)", &slot_0, QMetaData::Public },
	{ "goPressed()", &slot_1, QMetaData::Public },
	{ "countdown()", &slot_2, QMetaData::Public },
	{ "newButton()", &slot_3, QMetaData::Public },
	{ "resetButton()", &slot_4, QMetaData::Public },
	{ "loadButton()", &slot_5, QMetaData::Public },
	{ "sendButton()", &slot_6, QMetaData::Public },
	{ "saveState()", &slot_7, QMetaData::Public },
	{ "loadSet(const QString&)", &slot_8, QMetaData::Public },
	{ "newSet()", &slot_9, QMetaData::Public },
	{ "changeMode()", &slot_10, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"Packet", 3, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"Packet", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "Packet(int,const char*,int)", &signal_0, QMetaData::Public },
	{ "Packet(int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TweakWindow", parentObject,
	slot_tbl, 11,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TweakWindow.setMetaObject( metaObj );
    return metaObj;
}

void* TweakWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TweakWindow" ) ) return (TweakWindow*)this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL Packet
void TweakWindow::Packet( int t0, const char* t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_charstar.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL Packet
void TweakWindow::Packet( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool TweakWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newDataAvailable(static_QUType_int.get(_o+1)); break;
    case 1: goPressed(); break;
    case 2: countdown(); break;
    case 3: newButton(); break;
    case 4: resetButton(); break;
    case 5: loadButton(); break;
    case 6: sendButton(); break;
    case 7: saveState(); break;
    case 8: loadSet(static_QUType_QString.get(_o+1)); break;
    case 9: newSet(); break;
    case 10: changeMode(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TweakWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: Packet(static_QUType_int.get(_o+1),static_QUType_charstar.get(_o+2),static_QUType_int.get(_o+3)); break;
    case 1: Packet(static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool TweakWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
