pkgname=eofck
pkgdesc="A command to check that a file ends with a line feed"
pkgver=1
pkgrel=1
url="https://github.com/sibzou/$pkgname"
arch=(x86_64)
source=(git+https://github.com/sibzou/$pkgname.git)
sha256sums=("SKIP")

pkgver() {
    cd $pkgname
    git describe --always --tags
}

build() {
    mkdir build
    gcc $pkgname/$pkgname.c -o build/$pkgname
}

package() {
    mkdir -p $pkgdir/usr/bin
    cp build/$pkgname $pkgdir/usr/bin
}
