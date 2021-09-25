# $Id: Makefile 3112 2006-02-01 23:53:19Z mbm $

include $(TOPDIR)/rules.mk

PKG_NAME:=ubus
PKG_VERSION:=221ce7e
PKG_RELEASE:=1
PKG_MD5SUM:=daa4b5e3c4f1a2275723543a6eb411cb

PKG_SOURCE_URL:=http://dl.meraki.net
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_CAT:=zcat

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)
PKG_INSTALL_DIR:=$(PKG_BUILD_DIR)/ipkg-install

include $(TOPDIR)/package/rules.mk

$(eval $(call PKG_template,UBUS,ubus,$(PKG_VERSION)-$(PKG_RELEASE),$(ARCH)))

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

$(IPKG_UBUS):
	install -d -m0755 $(IDIR_UBUS)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libubus.so* $(IDIR_UBUS)/usr/lib/
	install -d -m0755 $(IDIR_UBUS)/usr/bin
	$(CP) $(PKG_INSTALL_DIR)/usr/bin/ubus $(IDIR_UBUS)/usr/bin/
	install -d -m0755 $(IDIR_UBUS)/usr/sbin
	$(CP) $(PKG_INSTALL_DIR)/usr/sbin/ubusd $(IDIR_UBUS)/usr/sbin/
	$(RSTRIP) $(IDIR_UBUS)
	$(IPKG_BUILD) $(IDIR_UBUS) $(PACKAGE_DIR)


install-dev: $(PKG_BUILD_DIR)/.built
	mkdir -p $(STAGING_DIR)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/ubus* $(STAGING_DIR)/usr/include/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/libubus* $(STAGING_DIR)/usr/include/
	mkdir -p $(STAGING_DIR)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libubus.so* $(STAGING_DIR)/usr/lib/

uninstall-dev:
	rm -rf \
		$(STAGING_DIR)/usr/include/ubus* \
		$(STAGING_DIR)/usr/include/libubus* \
		$(STAGING_DIR)/usr/lib/libubus.so*

compile-targets: install-dev
clean-targets: uninstall-dev

