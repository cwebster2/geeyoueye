/****************************************************************************
** PanelWidget meta object code from reading C++ file 'panel.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "panel.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PanelWidget::className() const
{
    return "PanelWidget";
}

QMetaObject *PanelWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PanelWidget;

#ifndef QT_NO_TRANSLATION
QString PanelWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PanelWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PanelWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PanelWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PanelWidget::staticMetaObject()
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
	{ "alt", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setAlt", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "tch", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_4 = {"setTach", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "v", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_5 = {"setASI", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "vs", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_6 = {"setVSI", 1, param_slot_6 };
    static const QUMethod slot_7 = {"callUpdate", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setHeading(float)", &slot_0, QMetaData::Public },
	{ "setRoll(float)", &slot_1, QMetaData::Public },
	{ "setPitch(float)", &slot_2, QMetaData::Public },
	{ "setAlt(float)", &slot_3, QMetaData::Public },
	{ "setTach(float)", &slot_4, QMetaData::Public },
	{ "setASI(float)", &slot_5, QMetaData::Public },
	{ "setVSI(float)", &slot_6, QMetaData::Public },
	{ "callUpdate()", &slot_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PanelWidget", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PanelWidget.setMetaObject( metaObj );
    return metaObj;
}

void* PanelWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PanelWidget" ) ) return (PanelWidget*)this;
    return QWidget::qt_cast( clname );
}

bool PanelWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setHeading(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 1: setRoll(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 2: setPitch(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 3: setAlt(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 4: setTach(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 5: setASI(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 6: setVSI(*((float*)static_QUType_ptr.get(_o+1))); break;
    case 7: callUpdate(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PanelWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PanelWidget::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
