/****************************************************************************
** WPTWidget meta object code from reading C++ file 'ap.h'
**
** Created: Thu Jul 19 20:29:15 2018
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "ap.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *WPTWidget::className() const
{
    return "WPTWidget";
}

QMetaObject *WPTWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_WPTWidget( "WPTWidget", &WPTWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString WPTWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WPTWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString WPTWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WPTWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* WPTWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"WPTWidget", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_WPTWidget.setMetaObject( metaObj );
    return metaObj;
}

void* WPTWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "WPTWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool WPTWidget::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool WPTWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool WPTWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool WPTWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *MapPointDialog::className() const
{
    return "MapPointDialog";
}

QMetaObject *MapPointDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MapPointDialog( "MapPointDialog", &MapPointDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MapPointDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MapPointDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MapPointDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MapPointDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MapPointDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"accept", 0, 0 };
    static const QUMethod slot_1 = {"reject", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "accept()", &slot_0, QMetaData::Public },
	{ "reject()", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "DMS", QUParameter::In },
	{ 0, &static_QUType_ptr, "DMS", QUParameter::In }
    };
    static const QUMethod signal_0 = {"newCoord", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "newCoord(DMS,DMS)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MapPointDialog", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MapPointDialog.setMetaObject( metaObj );
    return metaObj;
}

void* MapPointDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MapPointDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL newCoord
void MapPointDialog::newCoord( DMS t0, DMS t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

bool MapPointDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: accept(); break;
    case 1: reject(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MapPointDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newCoord((DMS)(*((DMS*)static_QUType_ptr.get(_o+1))),(DMS)(*((DMS*)static_QUType_ptr.get(_o+2)))); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool MapPointDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool MapPointDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *MapWidget::className() const
{
    return "MapWidget";
}

QMetaObject *MapWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MapWidget( "MapWidget", &MapWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MapWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MapWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MapWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MapWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MapWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"callUpdate", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "callUpdate()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MapWidget", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MapWidget.setMetaObject( metaObj );
    return metaObj;
}

void* MapWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MapWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool MapWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: callUpdate(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MapWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MapWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool MapWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *APWidget::className() const
{
    return "APWidget";
}

QMetaObject *APWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_APWidget( "APWidget", &APWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString APWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "APWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString APWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "APWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* APWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_0 = {"curX", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_1 = {"curY", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_2 = {"curZ", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "curX(float)", &slot_0, QMetaData::Public },
	{ "curY(float)", &slot_1, QMetaData::Public },
	{ "curZ(float)", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"APWidget", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_APWidget.setMetaObject( metaObj );
    return metaObj;
}

void* APWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "APWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool APWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: curX((float)(*((float*)static_QUType_ptr.get(_o+1)))); break;
    case 1: curY((float)(*((float*)static_QUType_ptr.get(_o+1)))); break;
    case 2: curZ((float)(*((float*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool APWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool APWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool APWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
