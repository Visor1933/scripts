sharedir = /usr/share/V1933
cur-dir  = $(shell pwd)
whoami   = $(shell whoami)

install:
	test -d $(sharedir) || sudo -p "sudo password for mkdir in /usr/share/" mkdir $(sharedir) && sudo chown $(whoami) $(sharedir)
	echo "wd=$(cur-dir)" > variables
	sudo mv variables ${sharedir}/
	mkdir localScripts
	gcc -march=native -O3 -pipe -o V1933bigComment ./bigComment/V1933bigComment.c
	sh ./V1933makeExec V1933makeExec && \
	if [ -e /usr/bin/V1933makeExec ] ; then \
		V1933makeExec findEverywhere & \
		V1933makeExec fixWifi & \
		V1933makeExec fixWifid & \
		V1933makeExec getphotos & \
		V1933makeExec initbash & \
		V1933makeExec initsh & \
		V1933makeExec initTex & \
		V1933makeExec mvExec & \
		V1933makeExec rmExec & \
		V1933makeExec rmphotos & \
		V1933makeExec V1933bigComment & \
		V1933makeExec V1933disableExec & \
		V1933makeExec V1933enableExec & \
		V1933makeExec V1933makeSelinux & \
		V1933makeExec viplombardUnzip & \
	fi

dep:
	test -e /bin/gphoto2 || dnf -y install gphoto2
	test -e /bin/gcc     || dnf -y install gcc

uninstall:
	sudo -p "sudo password for removing symlinks in /usr/bin/ and programms own folder in /usr/share/" \
	rm -rf /usr/bin/fixWifi \
	       /usr/bin/fixWifid \
		   /usr/bin/getphotos \
		   /usr/bin/initbash \
		   /usr/bin/initsh \
		   /usr/bin/initTex \
		   /usr/bin/mvExec \
		   /usr/bin/rmExec \
		   /usr/bin/rmphotos \
		   /usr/bin/V1933bigComment \
		   /usr/bin/V1933disableExec \
		   /usr/bin/V1933enableExec \
		   /usr/bin/V1933makeExec \
		   /usr/bin/V1933makeSelinux \
		   /usr/bin/viplombardUnzip \
		   /usr/share/V1933

clean:
	rm -rf variables V1933bigComment
