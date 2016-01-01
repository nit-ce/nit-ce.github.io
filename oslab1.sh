#!/bin/sh

gen()
{
	echo "$2" | tr + '\n' >$1
}

genseq()
{
	for i in `seq 1 $3`; do
		echo $2 $i >>$1
	done
}

mkdir oslab1 || exit 1

cd oslab1
echo "Generating oslab1/"

echo "OPERATING SYSTEM LABORATORY" >>README
echo "" >>README
echo "The skeleton of a common source directory." >>README
echo "Follow the instructions in oslab1.pdf." >>README
gen Makefile
# oslab1/src
mkdir src
cd src/
gen Makefile 'all: help+help:+	echo OSLab Test'
gen main.c '#include <stdio.h>+#include "hash.h"+#include "tbl.h"++int main(void)+{+	return 0;+}'
gen hash.c '#include "hash.h"++long hash(char *s)+{+	return 9;+}'
gen hash.h '/* hash.h */+long hash(char *s);'
gen str.c '#include <stdlib.h>+#include <string.h>+#include "str.h"++char *copystr(char *s)+{+	return malloc(strlen(s));+}'
gen str.h '/* str.h */+char *copystr(char *s);'
gen tbl.c '#include "tbl.h"++void tbl(char *s)+{+}'
gen tbl.h '/* tbl.h */+void tbl(char *s);'
gen pic.c '#include <stdio.h>+#include "pic.h"++void pic(char *s)+{+	printf("pic\\n");+}'
gen pic.h '/* pic.h */+void pic(char *s);'
gen hyph.c '#include <stdio.h>+#include "hyph.h"++void hyph(char *s)+{+	printf("hyph\\n");+}'
gen hyph.h '/* hyph.h */+void hyph(char *s);'
gen prep.c '#include <stdio.h>+#include "prep.h"++void prep(char *s)+{+	printf("prep\\n");+}'
gen prep.h '/* prep.h */+void prep(char *s);'
gen load.c '#include <stdio.h>+#include "load.h"++void load(char *s)+{+	printf("load\\n");+}'
gen load.h '/* load.h */+void load(char *s);'
# oslab1/src/lib
mkdir lib
cd lib/
gen Makefile
gen main.c '#include <stdio.h>+#include "lib.h"++void func2(char *s)+{+	printf("func2\\n");+}'
gen lib.c '#include <stdio.h>+#include "lib.h"++void func1(char *s)+{+	printf("func1\\n");+}'
gen lib.h '/* lib.h */+void func1(char *s);+void func2(char *s);+void man(void);'
gen man.c '#include <stdio.h>+#include "lib.h"++void man(void)+{+	printf("man\\n");+}'
cd ..
# oslab1/src/dep
mkdir dep
cd dep
gen Makefile 'all:+	echo Building dependencies'
gen regex.h '/* regex.h */+struct re *recomp(char *s);'
gen regex.c '#include <stdio.h>+#include "regex.h"++struct re *recomp(char *s)+{+	printf("recomp\\n");+	return NULL;+}'
gen util.h '/* util.h */+int recnt(char *s);'
for i in `seq 0 9`; do
	gen util$i.c "int util$i(void)+{+	return $i;+}"
done
cd ../..
# oslab1/doc
mkdir doc
cd doc/
gen main.txt "MAIN DOCUMENT++Just follow the instructions in oslab2.pdf."
gen guide.txt "USER'S GUIDE++This directory is generated automatically.+Follow the instructions and explain your observations."
dmesg | nl >log.txt
# oslab1/doc/demo
mkdir demo
cd demo/
gen Makefile 'all:+	echo Examples to show how it works'
gen example1.c '#include <stdio.h>+#include "pic.h"+#include "tbl.h"++int main(void)+{+	pic("test");+	return 0;+}'
gen example2.c '#include <stdio.h>+#include "pic.h"+#include "tbl.h"++int main(void)+{+	tbl("test");+	return 0;+}'
cd ../..
# oslab/test
mkdir test
cd test
gen Makefile 'all:+	echo Tests to make sure it works'
gen regex.c '#include <stdio.h>+#include "regex.h"++int main(void)+{+	recomp("pattern");+	return 0;+}'
gen main.c '#include <stdio.h>+#include "load.h"++int main(void)+{+	load("path");+	return 0;+}'
gen hash.c '#include <stdio.h>+#include "hash.h"++int main(void)+{+	hash("word");+	return 0;+}'
gen tbl.c '#include <stdio.h>+#include "tbl.h"++int main(void)+{+	tbl("tabular data");+	return 0;+}'
gen pic.c '#include <stdio.h>+#include "pic.h"++int main(void)+{+	pic("specification");+	return 0;+}'
gen test.sh 'for x in regex main hash tbl pic; do+	./$x+done'
cd ..
