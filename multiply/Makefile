clean:
	rm -rf ./Multiply.xcframework

clean-after:
	rm -rf ./libmultiply.a


build:
	cargo build --release --target aarch64-apple-ios-sim
	cargo build --release --target aarch64-apple-ios
	cargo build --release --target x86_64-apple-ios

header:
	cbindgen --config cbindgen.toml --output rust_header.h

lipo:
	lipo -create ./target/x86_64-apple-ios/release/libmultiply.a  \
		           ./target/aarch64-apple-ios-sim/release/libmultiply.a \
			 -output ./libmultiply.a

xcframework:
	xcodebuild -create-xcframework \
				 		 -library ./target/aarch64-apple-ios/release/libmultiply.a  -headers rust_header.h \
				 		 -library ./libmultiply.a                                   -headers rust_header.h \
				 		 -output  ./Multiply.xcframework

relocate:
	rm -rf ../ios/Frameworks/Multiply.xcframework
	mv ./Multiply.xcframework ../ios/Frameworks/

all: clean build header lipo xcframework relocate clean-after
