Documentation
===================-
Engines for Biology is covered by the terms of the GNU General Public License, version 2. For more information, please see COPYING.

Engines for Biology (e4b) is a MySQL plugin for biologists that includes storage engines and UDFs for working with biological data file format. e4b is good for applications such as complexity filtering.


e4b Requirements:
===================
To install e4b succesfully, you will need the following:
 * A working instance of MySQL (Version 5.1, for plugin support - support for newer versions is under development).
 * The source code matching your MySQL installation (source of recent versions are available at http://dev.mysql.com/downloads/, older versions at http://downloads.mysql.com/archives.php)
 * The development headers for MySQL
 * OpenSSL, and the development headers for OpenSSL installed (http://www.openssl.org/).
 * a working C compiler (e.g. gcc)
 * a working C++ compiler (e.g. g++)
 * expat, The Expat XML Parser (http://expat.sourceforge.net/)

Depending on how MySQL was installed, you may also need:
 * The path to your MySQL bin directory (automatically detected for most MySQL instances)
 * The path to your MySQL plugin directory (automatically detected for most MySQL instances)
 * The path to your MySQL include directory (automatically detected for most MySQL instances)


Installing e4b:
===================
In order to install e4b, first run the configure script, to generate the proper makefile. Include the directory of your MySQL source directory, using the --with-mysql-source argument:
$./configure --with-mysql-source=PATH_TO_MYSQL_SOURCE
For example:
$./configure --with-mysql-source=/home/iamauser/mysql-5.1.xx
(NOTE: using the ~ symbol in the directory argument will cause issues. Please type the full path to the MySQL source)
There may be certain errors that arise when running the configure script, typically depending on your MySQL installation, or not having the development tools for MySQL installed. If so, read the output after running ./configure and do as the error message suggests. Generally this will consist of assigning certain variables by hand. One can do so with the following arguments:
 * --with-mysql         : manually assign the path to your existing mysql installation
 * --with-mysql-bin	: manually assign the mysql bin directory
 * --with-mysql-include : manually assign the mysql include directory
 * --with-mysql-plugin  : manually assign the mysql plugin directory
 * --with-expat         : manually assign the expat library

Once the ./configure script runs without halting on any errors, the code can then be compiled by running Make, then Make install:
$make
$make install
Depending on your installation, or which user you are, you may need to run the make install command as root:
$sudo make install


Typical package requirements for Red Hat-based systems (yum install <package>):
===================
gcc or gcc-c++
openssl-devel

MySQL 5.1 from http://dev.mysql.com/downloads/
expat from source (http://expat.sourceforge.net)


Typical package requirements for Debian-based systems (apt-get install <package>):
===================
gcc or g++
libssl
libssl-dev
libexpat1
libexpat1-dev

mysql-server (if installing MySQL from packages)
libmysqlclient-dev (if installing MySQL from packages)
