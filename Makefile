# Docbook Makefile
# Red Liu(lli_njupt@163.com)

#XSLFILE=./docbook-xsl-ns-1.75.2/html/docbook.xsl
XSLFILE= ../docbook-xsl-ns-1.75.2/html/chunk.xsl
XML_FILE= index.xml
HTML_FILE=$(XML_FILE:.xml=.html)

all:  html

html : $(HTML_FILE)

%.html : %.xml ksync.xml device.xml armaddr.xml  armasm2.xml  arm.xml  atpcs2.xml  bootlinux.xml  hello1.xml linker.xml loader.xml elf.xml armhead.xml kernelinit.xml kernelinit2.xml linuxmode.xml bitmap.xml pagetab.xml armmu.xml resource.xml memory.xml parser.xml interrupt.xml kernelhead.xml timer.xml notifier.xml platform.xml preface.xml referrence.xml buddy.xml 
	xsltproc -o $(@F) --stringparam  section.autolabel 1 --stringparam html.stylesheet styles.css $(XSLFILE) $<

art : readme

readme: ./article/readme.xml
	xsltproc -o ./article/$(@F) --stringparam  section.autolabel 1 --stringparam html.stylesheet styles.css $(XSLFILE) $<
	
clean:
	rm -f *.html
