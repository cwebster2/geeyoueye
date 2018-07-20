/****************************************************************************
** MainWindow meta object code from reading C++ file 'vision.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "vision.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainWindow::className() const
{
    return "MainWindow";
}

QMetaObject *MainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainWindow;

#ifndef QT_NO_TRANSLATION
QString MainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"toggleDebug", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setStat1", 1, param_slot_1 };
    static const QUMethod slot_2 = {"about", 0, 0 };
    static const QUMethod slot_3 = {"aboutqt", 0, 0 };
    static const QUMethod slot_4 = {"picformats", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "toggleDebug()", &slot_0, QMetaData::Public },
	{ "setStat1(QString)", &slot_1, QMetaData::Public },
	{ "about()", &slot_2, QMetaData::Public },
	{ "aboutqt()", &slot_3, QMetaData::Public },
	{ "picformats()", &slot_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainWindow", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* MainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainWindow" ) ) return (MainWindow*)this;
    return QMainWindow::qt_cast( clname );
}

bool MainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: toggleDebug(); break;
    case 1: setStat1(static_QUType_QString.get(_o+1)); break;
    case 2: about(); break;
    case 3: aboutqt(); break;
    case 4: picformats(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainWindow::qt_property( int _id, int _f, QVariant* _v)
{
    return QMainWindow::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
