pkgname=eofck
pkgdesc="A command to check that a file ends with a line feed"
pkgver=1
pkgrel=1
url="https://github.com/sibzou/eofck"
arch=(x86_64)
depends=(glibc)
source=(git+https://github.com/sibzou/eofck.git)
sha256sums=("SKIP")

pkgver() {
    cd $srcdir/eofck
    git describe --always --tags
}

build() {
    mkdir $srcdir/build
    gcc $srcdir/eofck/eofck.c -o $srcdir/build/eofck
}

package() {
    mkdir -p $pkgdir/usr/bin
    cp $srcdir/build/eofck $pkgdir/usr/bin
}
