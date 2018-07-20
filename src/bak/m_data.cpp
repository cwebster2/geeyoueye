/****************************************************************************
** DataWidget meta object code from reading C++ file 'data.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "data.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DataWidget::className() const
{
    return "DataWidget";
}

QMetaObject *DataWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DataWidget;

#ifndef QT_NO_TRANSLATION
QString DataWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DataWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DataWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DataWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DataWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "hdg", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setHeading", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "deg", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setRoll", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "deg", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setPitch", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "coord", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setX", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "coord", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_4 = {"setY", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "coord", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_5 = {"setZ", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "rpm", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_6 = {"setTach", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "v", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_7 = {"setSpeed", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "z", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_8 = {"setVz", 1, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "setHeading(float)", &slot_0, QMetaData::Public },
	{ "setRoll(float)", &slot_1, QMetaData::Public },
	{ "setPitch(float)", &slot_2, QMetaData::Public },
	{ "setX(float)", &slot_3, QMetaData::Public },
	{ "setY(float)", &slot_4, QMetaData::Public },
	{ "setZ(float)", &slot_5, QMetaData::Public },
	{ "setTach(float)", &slot_6, QMetaData::Public },
	{ "setSpeed(float)", &slot_7, QMetaData::Public },
	{ "setVz(float)", &slot_8, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"DataWidget", parentObject,
	slot_tbl, 9,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DataWidget.setMetaObject( metaObj );
    return metaObj;
}

void* DataWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DataWidget" ) ) return (DataWidget*)this;
    return QWidget::qt_cast( clname );
}

bool DataWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setHeading(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 1: setRoll(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 2: setPitch(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 3: setX(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 4: setY(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 5: setZ(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 6: setTach(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 7: setSpeed(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 8: setVz(*((float*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DataWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DataWidget::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
