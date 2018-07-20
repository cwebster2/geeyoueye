/****************************************************************************
** UDPMaster meta object code from reading C++ file 'udpmaster.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "udpmaster.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *UDPMaster::className() const
{
    return "UDPMaster";
}

QMetaObject *UDPMaster::metaObj = 0;
static QMetaObjectCleanUp cleanUp_UDPMaster;

#ifndef QT_NO_TRANSLATION
QString UDPMaster::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "UDPMaster", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString UDPMaster::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "UDPMaster", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* UDPMaster::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_0 = {"newRoll", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_1 = {"newPitch", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_2 = {"newHeading", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_3 = {"newX", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_4 = {"newY", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_5 = {"newZ", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_6 = {"newSpeed", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_7 = {"newVz", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod signal_8 = {"newTach", 1, param_signal_8 };
    static const QMetaData signal_tbl[] = {
	{ "newRoll(float)", &signal_0, QMetaData::Public },
	{ "newPitch(float)", &signal_1, QMetaData::Public },
	{ "newHeading(float)", &signal_2, QMetaData::Public },
	{ "newX(float)", &signal_3, QMetaData::Public },
	{ "newY(float)", &signal_4, QMetaData::Public },
	{ "newZ(float)", &signal_5, QMetaData::Public },
	{ "newSpeed(float)", &signal_6, QMetaData::Public },
	{ "newVz(float)", &signal_7, QMetaData::Public },
	{ "newTach(float)", &signal_8, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"UDPMaster", parentObject,
	0, 0,
	signal_tbl, 9,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_UDPMaster.setMetaObject( metaObj );
    return metaObj;
}

void* UDPMaster::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "UDPMaster" ) ) return (UDPMaster*)this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL newRoll
void UDPMaster::newRoll( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newPitch
void UDPMaster::newPitch( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newHeading
void UDPMaster::newHeading( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newX
void UDPMaster::newX( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newY
void UDPMaster::newY( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newZ
void UDPMaster::newZ( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newSpeed
void UDPMaster::newSpeed( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newVz
void UDPMaster::newVz( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL newTach
void UDPMaster::newTach( float t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool UDPMaster::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool UDPMaster::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newRoll(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 1: newPitch(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 2: newHeading(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 3: newX(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 4: newY(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 5: newZ(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 6: newSpeed(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 7: newVz(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 8: newTach(*((float*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool UDPMaster::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
