/****************************************************************************
** PicThread meta object code from reading C++ file 'picload.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "picload.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PicThread::className() const
{
    return "PicThread";
}

QMetaObject *PicThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PicThread;

#ifndef QT_NO_TRANSLATION
QString PicThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PicThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PicThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"PicThread", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PicThread.setMetaObject( metaObj );
    return metaObj;
}

void* PicThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PicThread" ) ) return (PicThread*)this;
    if ( !qstrcmp( clname, "QThread" ) ) return (QThread*)this;
    return QObject::qt_cast( clname );
}

bool PicThread::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool PicThread::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PicThread::qt_property( int _id, int _f, QVariant* _v)
{
    return QObject::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES


const char *PicLoad::className() const
{
    return "PicLoad";
}

QMetaObject *PicLoad::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PicLoad;

#ifndef QT_NO_TRANSLATION
QString PicLoad::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicLoad", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PicLoad::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicLoad", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PicLoad::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"status", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "status(QString)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PicLoad", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PicLoad.setMetaObject( metaObj );
    return metaObj;
}

void* PicLoad::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PicLoad" ) ) return (PicLoad*)this;
    return QServerSocket::qt_cast( clname );
}

// SIGNAL status
void PicLoad::status( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool PicLoad::qt_invoke( int _id, QUObject* _o )
{
    return QServerSocket::qt_invoke(_id,_o);
}

bool PicLoad::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: status(static_QUType_QString.get(_o+1)); break;
    default:
	return QServerSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PicLoad::qt_property( int _id, int _f, QVariant* _v)
{
    return QServerSocket::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
