/****************************************************************************
** PicWidget meta object code from reading C++ file 'pic.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "pic.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PicWidget::className() const
{
    return "PicWidget";
}

QMetaObject *PicWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PicWidget;

#ifndef QT_NO_TRANSLATION
QString PicWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PicWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PicWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QImage", QUParameter::In }
    };
    static const QUMethod slot_0 = {"newPic", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "data", &static_QUType_charstar, 0, QUParameter::In },
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"newPic", 2, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "newPic(QImage*)", &slot_0, QMetaData::Public },
	{ "newPic(char*,int)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"stat2", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "stat2(QString)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PicWidget", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PicWidget.setMetaObject( metaObj );
    return metaObj;
}

void* PicWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PicWidget" ) ) return (PicWidget*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL stat2
void PicWidget::stat2( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool PicWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newPic((QImage*)static_QUType_ptr.get(_o+1)); break;
    case 1: newPic(static_QUType_charstar.get(_o+1),static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PicWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: stat2(static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool PicWidget::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES


const char *PicWindow::className() const
{
    return "PicWindow";
}

QMetaObject *PicWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PicWindow;

#ifndef QT_NO_TRANSLATION
QString PicWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PicWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PicWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PicWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "q", &static_QUType_ptr, "QImage", QUParameter::In }
    };
    static const QUMethod slot_0 = {"newPic", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "data", &static_QUType_charstar, 0, QUParameter::In },
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"newPic", 2, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "newPic(QImage*)", &slot_0, QMetaData::Public },
	{ "newPic(char*,int)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"PicWindow", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PicWindow.setMetaObject( metaObj );
    return metaObj;
}

void* PicWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PicWindow" ) ) return (PicWindow*)this;
    return QWidget::qt_cast( clname );
}

bool PicWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newPic((QImage*)static_QUType_ptr.get(_o+1)); break;
    case 1: newPic(static_QUType_charstar.get(_o+1),static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PicWindow::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PicWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
