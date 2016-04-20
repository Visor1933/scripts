install:
	test -d /usr/share/V1933 || mkdir /usr/share/V1933
	echo "wd=\\" > variables
	pwd >> variables
	cp variables /usr/share/V1933/
	cp defaultTex /usr/share/V1933/initTex/
	#mv db.xml /usr/share/V1933/
	./V1933makeExec V1933makeExec
	V1933makeExec getphotos
	V1933makeExec initbash
	V1933makeExec initsh
	V1933makeExec initTex
	V1933makeExec rmphotos
	V1933makeExec V1933disableExec
	V1933makeExec V1933enableExec
	V1933makeExec V1933makeSelinux
	V1933makeExec mvExec
	V1933makeExec rmExec
	V1933makeExec viplombardUnzip

finish:
	test -f /usr/share/V1933/variables && rm -f variables
	test -f /usr/share/V1933/initTex/defaultTex && rm -f variables

dep:
	test -e /bin/gphoto2 || dnf -y install gphoto2