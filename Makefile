#MySQL5? @MYSQL5@

SRCS = util/util.cc util/transparent_file.cc
subdirs = fasta fastq blast_fmt6 protXML

HDRS = $(SRCS:.cc=.h)

OBJS = $(SRCS:.cc=.o)

CXX = gcc 
CXXFLAGS = -g -O2 -fno-implicit-templates -fno-exceptions -fno-rtti -m64

MYSQL_FLAGS = -DMYSQL_DYNAMIC_PLUGIN 
MYSQL_INC = -Isql -Iinclude -Iregex -Iutil -I/opt/local/include  
MYSQL_RPATH = /usr/local/mysql/lib/plugin


all: $(OBJS)
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) all) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

.cc.o: $(HDRS)
	$(CXX) $(CXXFLAGS) $(MYSQL_FLAGS) $(MYSQL_INC) -fno-common -fPIC -c $< -o $@

install: real_install

real_install:
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) install) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

clean:
	\rm -rf ${OBJS}
	@for dir in ${subdirs}; do \
	  (cd $$dir && $(MAKE) clean) \
	  || case "$(MFLAGS)" in *k*) fail=yes;; *) exit 1;; esac; \
	done && test -z "$$fail"

test:
	@echo "To test wether an engine installed properly, you can do this by:"
	@echo "Placing a test file in the temp directory:"
	@echo "%rm -rf /tmp/test.fastq"
	@echo "%cp test.fastq /tmp/fastq"
	@echo "Giving the file the proper permissions:"
	@echo "%chmod oug+rwk /tmp/test.fastq"
	@echo "Then running the test sql file:"
	@echo "%mysql /tmp/test.fastq"
	@echo "Then clearning the temp file after the test is finished:"
	@echo "%rm -rf /tmp/test.fastq"
	

# flag for development of the template storage engine, put your setup line in here
# and force code regeneration for all of the template based engines
default: template/Makefile
	# e.g. OS/X
	#./setup /Users/dacb/mysql/mysql-5.1.37 /usr/local/mysql/lib/plugin 64 -bundle /usr/include /usr/local/mysql
	# linux on Hyak

