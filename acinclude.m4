# $Id: acinclude.m4,v 1.9 2002/07/21 00:11:43 casey Exp $

AC_DEFUN([CCW_CFLAGS],
[
	AC_ARG_ENABLE(debug,
		[  --enable-debug          Turn on debugging],
		[case "${enableval}" in
			yes) debug=true ;;
			no)  debug=false ;;
			*) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
		esac],[debug=false])
	AC_ARG_ENABLE(profile,
		[  --enable-profile        Turn on profiling (implies debug)],
		[case "${enableval}" in
			yes) profile=true ;;
			no)  profile=false ;;
			*) AC_MSG_ERROR(bad value ${enableval} for --enable-profile) ;;
		esac],[profile=false])

	if test x"$profile" = x"true"; then
		debugflags="-pg -g3 -O2 -DDEBUG"
	else 
		if test x"$debug" = x"true"; then
			debugflags="-g -O2 -DDEBUG"
		else
			debugflags="-g0 -O3"
		fi
	fi

#	AC_MSG_NOTICE(target_cpu $target_cpu)
#	cpu=`echo "$target_cpu" | sed 's%i\(.86\)%\1%'`
#	AC_MSG_NOTICE(cpu $cpu)
#	CXXFLAGS="$debugflags -march=${target_cpu}"
	CXXFLAGS="$debugflags"
])

AC_DEFUN([CCW_PROG_QTMT],
[
	AC_REQUIRE([AC_PROG_CXX])
	AC_REQUIRE([AC_PATH_X])
	AC_REQUIRE([AC_PATH_XTRA])

	#AC_MSG_CHECKING(for multithreaded QT library)
       
        AC_ARG_WITH([Qt-includes],
		[  --with-Qt-includes=DIR  Qt include files are in DIR])
	AC_ARG_WITH([Qt-dir],
		[  --with-Qt-dir=DIR       Qt library files are in DIR/lib/])
	
	CCW_QT_FLAGS

	# Look for moc here
        QT_MOC="/opt/local/lib/qt3/bin/moc"

	CCW_QT_LIB

        
	AC_MSG_NOTICE([QT Compile Flags $QT_CXXFLAGS])
	AC_MSG_NOTICE([QT Library Flags $QT_LDFLAGS])
	AC_MSG_NOTICE([QT MOC Path      $QT_MOC])

	AC_SUBST(QT_CXXFLAGS)
	AC_SUBST(QT_LDFLAGS)
	AC_SUBST(QT_MOC)
])	
 



AC_DEFUN([CCW_QT_FLAGS],
[
	AC_MSG_CHECKING(for qt compile time flags)
	# Determine CXXFLAGS for compiling with QT
	qtmt_test_header=qapplication.h

	AC_TRY_CPP([#include <$qtmt_test_header>],
	[
		#it worked
		ccw_cxxflags="-DQT_THREAD_SUPPORT"
	],[
		#didnt work
		echo "Please disregard above error." >&AC_FD_CC

		ccw_include_list="
			$QTDIR/include
			$with_Qt_includes
			/usr/include/qt
			/opt/local/lib/qt3/include
		"

		for ccw_dir in $ccw_include_list; do
			if test -r "$ccw_dir/$qtmt_test_header"; then
				ccw_cxxflags="-I$ccw_dir -DQT_THREAD_SUPPORT"
				break
			fi
		done
	])
	if test x"$ccw_cxxflags" != x; then
		AC_MSG_RESULT([$ccw_cxxflags])
		QT_CXXFLAGS="$ccw_cxxflags"
	else
		AC_MSG_WARN([QT Include path not found])
	fi
])

AC_DEFUN([CCW_QT_LIB],
[
	ccw_try_lib=qt-mt
	CCW_QT_LIB_PATH
	if test x"$ccw_found" = x"1"; then
		CCW_QT_LIB_THREADED
		if test x"$ccw_thread" = x"1"; then
			ccw_ldflags="$ccw_test_ldflags"
		else
			ccw_try_lib=qt-mt
			CCW_QT_LIB_PATH
			if test x"$ccw_found" = x"1"; then
				CCW_QT_LIB_THREADED
				if test x"$ccw_thread" = x"1"; then
					ccw_ldflags="$ccw_test_ldflags"
				fi
			fi
		fi
	fi
	if test x"$ccw_ldflags" = x""; then
		AC_MSG_ERROR([Could not find a QT library supporting threads])
	fi
	QT_LDFLAGS=$ccw_test_ldflags
])

AC_DEFUN([CCW_QT_LIB_PATH],
[
	AC_MSG_CHECKING(for $ccw_try_lib library path)
	ccw_test_main="
		int argc;
		char **argv;
		QApplication(argc,argv);
	"
	ccw_save_LIBS="$LIBS"
	LIBS="-l$ccw_try_lib"
        ccw_save_CXXFLAGS="$CXXFLAGS"
	CXXFLAGS="$ccw_cxxflags"
	AC_TRY_LINK([#include <$qtmt_test_header>], $ccw_test_main,
	[
		#success -- can we ever get here?
		ccw_test_ldflags="$LIBS"
		ccw_moc_path="/opt/local/lib/qt3/bin/moc"
	],[
		#didnt work
		echo "Please disregard above error." >&AC_FD_CC
		ccw_dir_list="
			$QTDIR
			$with_Qt_dir
			/usr
			/opt/local/lib/qt3
		"

		for ccw_dir in $ccw_dir_list; do
			for ccw_ext in a so sl; do
				if test -r $ccw_dir/lib/lib$ccw_try_lib.$ccw_ext; then
					ccw_test_ldflags="-L$ccw_dir/lib $LIBS"
					ccw_moc_path="$ccw_dir/bin/moc"
					break 2
				fi
			done
		done
	])
	if test x"$ccw_test_ldflags" != x; then
		AC_MSG_RESULT([$ccw_test_ldflags])
		QT_MOC="$ccw_moc_path"
		ccw_found=1
	else
		AC_MSG_WARN([QT library not found])
		ccw_found=0
	fi
	LIBS="$ccw_save_LIBS"
	CXXFLAGS="$ccw_save_CXXFLAGS"
		
])

AC_DEFUN([CCW_QT_LIB_THREADED],
[
	## ccw_try_lib and ccw_test_ldflags have stuff in them
	AC_MSG_CHECKING(for $ccw_try_lib thread support)

	AC_MSG_RESULT([yes])
	ccw_thread=1
])
