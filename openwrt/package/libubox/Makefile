# $Id: Makefile 3112 2006-02-01 23:53:19Z mbm $

include $(TOPDIR)/rules.mk

PKG_NAME:=libubox
PKG_VERSION:=eeef7b5
PKG_RELEASE:=1
PKG_MD5SUM:=7d8c0803e6b3a94092edfb998042e7cd

PKG_SOURCE_URL:=http://dl.meraki.net
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_INSTALL_DIR:=$(PKG_BUILD_DIR)/ipkg-install

include $(TOPDIR)/package/rules.mk

$(eval $(call PKG_template,LIBUBOX,libubox,$(PKG_VERSION)-$(PKG_RELEASE),$(ARCH)))

$(PKG_BUILD_DIR)/.configured: $(PKG_BUILD_DIR)/.prepared
	(cd $(PKG_BUILD_DIR); $(TARGET_CONFIGURE_OPTS) \
		CFLAGS="$(TARGET_CFLAGS)" \
		CPPFLAGS="-I$(STAGING_DIR)/usr/include" \
		LDFLAGS="-L$(STAGING_DIR)/usr/lib" \
		cmake \
			-DCMAKE_INSTALL_PREFIX="$(PKG_INSTALL_DIR)/usr" \
			-DCMAKE_FIND_ROOT_PATH="$(STAGING_DIR)" \
			-DCMAKE_C_COMPILER="$(TARGET_CROSS)gcc" \
			-DPKG_CONFIG_EXECUTABLE="$(TARGET_CROSS)pkg-config" \
			-DBUILD_LUA=OFF \
			-DBUILD_EXAMPLES=OFF; \
	)
	touch $@

$(PKG_BUILD_DIR)/.built:
	rm -rf $(PKG_INSTALL_DIR)
	mkdir -p $(PKG_INSTALL_DIR)
	$(MAKE) -C $(PKG_BUILD_DIR) \
		all install
	touch $@

#There's additional files we don't copy here to reduce node space usage
#If you want shell script JSON parsing or similar you'll need to add copies for them

$(IPKG_LIBUBOX):
	install -d -m0755 $(IDIR_LIBUBOX)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libubox.so* $(IDIR_LIBUBOX)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libblobmsg_json.so* $(IDIR_LIBUBOX)/usr/lib
	$(RSTRIP) $(IDIR_LIBUBOX)
	$(IPKG_BUILD) $(IDIR_LIBUBOX) $(PACKAGE_DIR)


install-dev: $(PKG_BUILD_DIR)/.built
	mkdir -p $(STAGING_DIR)/usr/include/libubox
	$(CP) $(PKG_INSTALL_DIR)/usr/include/libubox/* $(STAGING_DIR)/usr/include/libubox
	mkdir -p $(STAGING_DIR)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libubox.so* $(STAGING_DIR)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libblobmsg_json.so* $(STAGING_DIR)/usr/lib/

uninstall-dev:
	rm -rf \
		$(STAGING_DIR)/usr/include/libubox \
		$(STAGING_DIR)/usr/lib/libubox* \
		$(STAGING_DIR)/usr/lib/libblobmsg_json*

compile-targets: install-dev
clean-targets: uninstall-dev

