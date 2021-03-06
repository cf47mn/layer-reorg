
#-------------------------------------------------
## Graphics section ##
#-------------------------------------------------
PACKAGES_GFX_${MACHINE} = "omapdrm-pvr"

# Enable Gfx Pkgs
MACHINE_FEATURES_append = " sgx"
MULTI_PROVIDER_WHITELIST += "virtual/libgl virtual/egl virtual/libgles1 virtual/libgles2"

DEPENDS_remove = "virtual/libgl"

# Preferred providers
PREFERRED_PROVIDER_virtual/libgles1 = ""
PREFERRED_PROVIDER_virtual/libgles2 = "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/egl      = "ti-sgx-ddk-um"
PREFERRED_PROVIDER_virtual/mesa     = "mesa-gl"
PREFERRED_PROVIDER_libgbm           = "libgbm"

#Preferred versions
PREFERRED_VERSION_libgbm            = "10.0.0"

#-------------------------------------------------
## Multimedia section ##
#-------------------------------------------------

GSTREAMER_PLUGINS = " \
     gstreamer1.0-plugins-bad-meta \
     gstreamer1.0-plugins-ducati \
     gstreamer1.0-plugins-vpe \
"

PACKAGES_MULTIMEDIA   = " \
    ipumm-fw \
    pulseaudio-misc      \
    ${GSTREAMER_PLUGINS} \
"

PREFERRED_VERSION_ipumm-fw          = "3.00.13.00"

PREFERRED_PROVIDER_virtual/kernel  = "linux-ti-staging"
PREFERRED_VERSION_virtual/kernel  = "4.9"

# Distribution-specific runtime components
IMAGE_INSTALL_append = " \
     ${PACKAGES_GFX}     \
     ${PACKAGES_MULTIMEDIA}     \
     cmem \
"
