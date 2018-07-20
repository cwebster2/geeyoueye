/****************************************************************************
** DebugWindow meta object code from reading C++ file 'debug.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "debug.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *DebugWindow::className() const
{
    return "DebugWindow";
}

QMetaObject *DebugWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_DebugWindow;

#ifndef QT_NO_TRANSLATION
QString DebugWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DebugWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString DebugWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "DebugWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* DebugWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_0 = {"guiDebug", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_charstar, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"guiDebug", 1, param_slot_1 };
    static const QUMethod slot_2 = {"clearPressed", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"maxlinesChanged", 1, param_slot_3 };
    static const QUMethod slot_4 = {"browsePressed", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"togglefile", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "guiDebug(QString&)", &slot_0, QMetaData::Public },
	{ "guiDebug(const char*)", &slot_1, QMetaData::Public },
	{ "clearPressed()", &slot_2, QMetaData::Public },
	{ "maxlinesChanged(const QString&)", &slot_3, QMetaData::Public },
	{ "browsePressed()", &slot_4, QMetaData::Public },
	{ "togglefile(bool)", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"DebugWindow", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_DebugWindow.setMetaObject( metaObj );
    return metaObj;
}

void* DebugWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "DebugWindow" ) ) return (DebugWindow*)this;
    return QWidget::qt_cast( clname );
}

bool DebugWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: guiDebug(static_QUType_QString.get(_o+1)); break;
    case 1: guiDebug(static_QUType_charstar.get(_o+1)); break;
    case 2: clearPressed(); break;
    case 3: maxlinesChanged(static_QUType_QString.get(_o+1)); break;
    case 4: browsePressed(); break;
    case 5: togglefile(static_QUType_bool.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool DebugWindow::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool DebugWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
