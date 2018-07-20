#!/bin/sh
#
# $Id: autogen.sh,v 1.6 2001/11/14 23:32:50 casey Exp $
#
# Requires: automake, autoconf, dpkg-dev
set -e

# Refresh GNU autotools toolchain.
aclocal
autoheader
automake --gnu --add-missing 

# The automake package already links config.sub/guess to /usr/share/misc/
for i in config.guess config.sub ; do
	test -r /usr/share/automake/${i} && cp -f /usr/share/automake/${i} .
	chmod 755 ${i}
done

autoconf

exit 0
