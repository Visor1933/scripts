sharedir = /usr/share/V1933
cur-dir  = $(shell pwd)
whoami   = $(shell whoami)

install:
	test -d $(sharedir) || sudo -p "sudo password for mkdir in /usr/share/" mkdir $(sharedir) && sudo chown $(whoami) $(sharedir)
	echo "wd=$(cur-dir)" > variables
	sudo mv variables ${sharedir}/
	test -d localScripts || mkdir localScripts
	(cd bigComment && make && make clean && cp V1933bigComment ../)
	sh ./V1933makeExec V1933makeExec
	test -e /usr/local/bin/V1933makeExec && ( \
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
		V1933makeExec V1933commit & \
		V1933makeExec V1933disableExec & \
		V1933makeExec V1933enableExec & \
		V1933makeExec V1933makeSelinux & \
		V1933makeExec V1933mvExec & \
		V1933makeExec V1933rmExec & \
	)
	sleep 1

dep:
	test -e /bin/gphoto2 || dnf -y install gphoto2 || emerge -v gphoto2 || apt -y install gphoto2
	test -e /bin/gcc     || dnf -y install gcc || emerge -v gcc || apt -y install gcc
	test -e /bin/dash    || dnf -y install dash || emerge -v dash || apt -y install dash

uninstall:
	rm -rf /usr/local/bin/fixWifi \
	       /usr/local/bin/fixWifid \
	       /usr/local/bin/getphotos \
	       /usr/local/bin/initbash \
	       /usr/local/bin/initsh \
	       /usr/local/bin/initTex \
	       /usr/local/bin/mvExec \
	       /usr/local/bin/rmExec \
	       /usr/local/bin/rmphotos \
	       /usr/local/bin/V1933bigComment \
	       /usr/local/bin/V1933disableExec \
	       /usr/local/bin/V1933enableExec \
	       /usr/local/bin/V1933makeExec \
	       /usr/local/bin/V1933makeSelinux \
	       /usr/local/share/V1933
	test -e /var/tmp/fixWifid.log && rm /var/tmp/fixWifid.log || true

clean:
	rm -rf variables V1933bigComment
