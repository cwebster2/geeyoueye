/****************************************************************************
** TelData meta object code from reading C++ file 'teldata.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "teldata.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TelData::className() const
{
    return "TelData";
}

QMetaObject *TelData::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TelData;

#ifndef QT_NO_TRANSLATION
QString TelData::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TelData", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TelData::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TelData", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TelData::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"end", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "end()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TelData", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TelData.setMetaObject( metaObj );
    return metaObj;
}

void* TelData::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TelData" ) ) return (TelData*)this;
    if ( !qstrcmp( clname, "QThread" ) ) return (QThread*)this;
    return QObject::qt_cast( clname );
}

bool TelData::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: end(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TelData::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TelData::qt_property( int _id, int _f, QVariant* _v)
{
    return QObject::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
