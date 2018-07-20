/****************************************************************************
** TCPPic meta object code from reading C++ file 'tcppic.h'
**
** Created: Wed Jul 24 06:50:20 2002
**      by: The Qt MOC ($Id:  qt/moc_yacc.cpp   3.0.4   edited Apr 26 09:47 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "tcppic.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 19)
#error "This file was generated using the moc from 3.0.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TCPPic::className() const
{
    return "TCPPic";
}

QMetaObject *TCPPic::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TCPPic;

#ifndef QT_NO_TRANSLATION
QString TCPPic::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TCPPic", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TCPPic::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TCPPic", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TCPPic::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"status", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "status(QString)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TCPPic", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TCPPic.setMetaObject( metaObj );
    return metaObj;
}

void* TCPPic::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TCPPic" ) ) return (TCPPic*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL status
void TCPPic::status( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool TCPPic::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool TCPPic::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: status(static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool TCPPic::qt_property( int _id, int _f, QVariant* _v)
{
    return QWidget::qt_property( _id, _f, _v);
}
#endif // QT_NO_PROPERTIES
