SUMMARY = "gbm library"
LICENSE = "MIT"
SECTION = "libs"

LIC_FILES_CHKSUM = " \
    file://gbm.c;beginline=4;endline=22;md5=5cdaac262c876e98e47771f11c7036b5"

SRCREV = "bc04aefc9d5322f8b2dc1ecb15d0713bbab684b8"
SRC_URI = "git://github.com/renesas-rcar/libgbm;branch=rcar-gen3"

S = "${WORKDIR}/git"

COMPATIBLE_MACHINE = "(r8a7795|r8a7796)"
DEPENDS = "wayland-kms"

inherit autotools pkgconfig

PACKAGES = " \
    ${PN} \
    ${PN}-dev \
    ${PN}-dbg \
    ${PN}-staticdev \
"

FILES_${PN} = " \
    ${libdir}/libgbm.so.* \
    ${libdir}/gbm/libgbm_kms.so.* \
    ${libdir}/gbm/*.so \
    ${libdir}/*.so \
"
FILES_${PN}-dev += "${libdir}/gbm/*.la"
FILES_${PN}-dbg += "${libdir}/gbm/.debug/*"
FILES_${PN}-staticdev += "${libdir}/gbm/*.a"

INSANE_SKIP_${PN} += "dev-so"
