include $(TOPDIR)/rules.mk

PKG_NAME:=talloc
PKG_VERSION:=samba-3.0.37
PKG_RELEASE:=2
PKG_MD5SUM:=5d5b15749be24b435f798421cb7ad572

PKG_SOURCE_URL:=http://dl.meraki.net
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_INSTALL_DIR:=$(PKG_BUILD_DIR)/ipkg-install

include $(TOPDIR)/package/rules.mk

$(eval $(call PKG_template,TALLOC,talloc,$(PKG_VERSION)-$(PKG_RELEASE),$(ARCH)))

$(PKG_BUILD_DIR)/.configured:
	(cd $(PKG_BUILD_DIR); rm -rf config.{cache,status} ; \
		$(TARGET_CONFIGURE_OPTS) \
		CC="$(TARGET_CC)" \
		CFLAGS="$(strip $(TARGET_CFLAGS)) -std=c99 -fPIC" \
		CPPFLAGS="-I$(STAGING_DIR)/usr/include" \
		LDFLAGS="-L$(STAGING_DIR)/usr/lib" \
		PKGCONFIG="$(TARGET_CROSS)pkg-config" \
		./configure \
		  --target=$(GNU_TARGET_NAME) \
		  --host=$(GNU_TARGET_NAME) \
		  --build=$(GNU_HOST_NAME) \
		  --program-prefix="" \
		  --prefix=/usr \
		  --exec-prefix=/usr \
		  --bindir=/usr/bin \
		  --datadir=/usr/share \
		  --includedir=/usr/include \
		  --infodir=/usr/share/info \
		  --libdir=/usr/lib \
		  --libexecdir=/usr/lib \
		  --localstatedir=/var \
		  --mandir=/usr/share/man \
		  --sbindir=/usr/sbin \
		  --sysconfdir=/etc \
		  $(DISABLE_LARGEFILE) \
	);
	touch $@

$(PKG_BUILD_DIR)/.built:
	rm -rf $(PKG_INSTALL_DIR)
	mkdir -p $(PKG_INSTALL_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR)/ \
		CFLAGS_O="$(TARGET_CFLAGS)" \
		CC="$(TARGET_CC)" DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
	touch $@

$(IPKG_TALLOC):
	install -d -m0755 $(IDIR_TALLOC)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libtalloc.a $(IDIR_TALLOC)/usr/lib
	$(RSTRIP) $(IDIR_TALLOC)
	$(IPKG_BUILD) $(IDIR_TALLOC) $(PACKAGE_DIR)

$(STAGING_DIR)/usr/lib/libtalloc.a: $(PKG_BUILD_DIR)/.built
	mkdir -p $(STAGING_DIR)/usr/include/talloc
	$(CP) $(PKG_INSTALL_DIR)/usr/include/talloc.h $(STAGING_DIR)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/*.h $(STAGING_DIR)/usr/include/talloc
	mkdir -p $(STAGING_DIR)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libtalloc.a $(STAGING_DIR)/usr/lib
	mkdir -p $(STAGING_DIR)/usr/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/talloc.pc $(STAGING_DIR)/usr/lib/pkgconfig
	touch $(STAGING_DIR)/usr/lib/libtalloc.a

install-dev: $(STAGING_DIR)/usr/lib/libtalloc.a

uninstall-dev:
	rm -rf \
	  $(STAGING_DIR)/usr/include/talloc*.h \
	  $(STAGING_DIR)/usr/include/talloc \
	  $(STAGING_DIR)/usr/lib/pkgconfig/talloc.pc \
	  $(STAGING_DIR)/usr/lib/libtalloc.so* \
	  $(STAGING_DIR)/usr/lib/libtalloc.a \

compile-targets: install-dev
clean-targets: uninstall-dev
