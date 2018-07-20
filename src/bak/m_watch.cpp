/****************************************************************************
** WatchWindow meta object code from reading C++ file 'watch.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "watch.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *WatchWindow::className() const
{
    return "WatchWindow";
}

QMetaObject *WatchWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_WatchWindow;

#ifndef QT_NO_TRANSLATION
QString WatchWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WatchWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString WatchWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "WatchWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* WatchWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"WatchWindow", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_WatchWindow.setMetaObject( metaObj );
    return metaObj;
}

void* WatchWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "WatchWindow" ) ) return (WatchWindow*)this;
    return QWidget::qt_cast( clname );
}

bool WatchWindow::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool WatchWindow::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool WatchWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
