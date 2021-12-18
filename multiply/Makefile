build:
	cargo build --target "aarch64-apple-ios-sim" 
	cargo build --target "aarch64-apple-ios" 

rename:
	mv ./target/aarch64-apple-ios/debug/libmultiply.a ./target/aarch64-apple-ios/debug/libmultiply-device.a
	mv ./target/aarch64-apple-ios-sim/debug/libmultiply.a ./target/aarch64-apple-ios-sim/debug/libmultiply-sim.a

header:
	cbindgen --config cbindgen.toml --output rust_header.h

framework:
	xcodebuild -create-xcframework \
		          -library target/aarch64-apple-ios-sim/debug/libmultiply-sim.a \
		          -library target/aarch64-apple-ios/debug/libmultiply-device.a -headers ./rust_header.h \
							-output ../ios/Frameworks/multi.xcframework

all: build header rename framework
