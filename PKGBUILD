# tEM! was here
pkgname=temlang
pkgver=1.0
pkgrel=1
pkgdesc="tEM find hoomans... SO CUTE! but hooman language make tEM SO CONFUS! tem hav SOLUTION! tem made HOOMAN TO TEMMIE translator!"
arch=('x86_64' 'i686')
url=""
license=('MIT')
depends=('gcc')
source=('main.c')
md5sums=('SKIP') 

build() {
    cd "$srcdir"
    gcc -o temlang main.c
}

package() {
    cd "$srcdir"
    install -Dm755 temlang "$pkgdir/usr/bin/temlang"
}
