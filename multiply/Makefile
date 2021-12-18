build:
	cargo build --target "aarch64-apple-darwin" 

build-ios:
	cargo build --target "aarch64-apple-ios" 

build-ios-sim:
	cargo build --target "aarch64-apple-ios-sim"

build-lipo:
	cargo lipo --release

headers:
	cbindgen --config cbindgen.toml --crate multiply --output rust_multiply.h

relocate:
	mv ./target/aarch64-apple-ios/debug/libmultiply.a ../ios/libmultiply.a
	mv ./rust_multiply.h ../cpp/rust_multiply.h

relocate-sim:
	mv ./target/aarch64-apple-ios-sim/debug/libmultiply.a ../ios/libmultiply.a
	mv ./rust_multiply.h ../cpp/rust_multiply.h

relocate-lipo:
	cp ./target/universal/release/libmultiply.a ../ios/libmultiply.a
	cp ./rust_multiply.h ../cpp/rust_multiply.h

all: build-ios headers relocate

sim: build-ios-sim headers relocate-sim

lipo: build-lipo headers relocate-lipo
