# --- Generic --- 

# Create headers
header:
	cbindgen --config cbindgen.toml --output rust_header.h

# --- iOS --- 

# Clean ios framework
ios-clean:
	rm -rf ./ios/Multiply.xcframework

# Build ios targets
ios-build:
	cargo build --release --target aarch64-apple-ios-sim
	cargo build --release --target aarch64-apple-ios
	cargo build --release --target x86_64-apple-ios

# Combine simulator architectures
ios-lipo:
	lipo -create ./target/x86_64-apple-ios/release/libmultiply.a  \
		           ./target/aarch64-apple-ios-sim/release/libmultiply.a \
			 -output ./ios/libmultiply.a

# generate framework
ios-xcframework:
	xcodebuild -create-xcframework \
				 		 -library ./target/aarch64-apple-ios/release/libmultiply.a -headers rust_header.h \
				 		 -library ./ios/libmultiply.a                              -headers rust_header.h \
				 		 -output  ./ios/Multiply.xcframework

# Move to correct location for example app
ios-relocate:
	rm -rf ../ios/Frameworks/Multiply.xcframework
	cp -r ./ios/Multiply.xcframework ../ios/Frameworks/

# Full ios script
ios-all: ios-clean ios-build header ios-lipo ios-xcframework ios-relocate

# --- Android ---

# Clean android libraries
android-clean:
	rm -rf ./android/libs

# build android targets
android-build:
	cargo build --release --target aarch64-linux-android
	cargo build --release --target armv7-linux-androideabi
	cargo build --release --target x86_64-linux-android
	cargo build --release --target i686-linux-android
	#cargo build --release --target arm-linux-androideabi

# Move to correct location for example app
android-relocate:
	mkdir ./android/libs/
	mkdir ./android/libs/x86/
	mkdir ./android/libs/x86_64/
	mkdir ./android/libs/armeabi-v7a/
	mkdir ./android/libs/arm64-v8a/
	mv ./target/aarch64-linux-android/release/libmultiply.a ./android/libs/arm64-v8a
	mv ./target/armv7-linux-androideabi/release/libmultiply.a ./android/libs/armeabi-v7a
	mv ./target/x86_64-linux-android/release/libmultiply.a ./android/libs/x86_64
	mv ./target/i686-linux-android/release/libmultiply.a ./android/libs/x86
	#mv ./target/arm-linux-androideabi/release/libmultiply.a ./android/libs/
	cp -r ./android/libs ../android
	cp ./rust_header.h ../cpp/rust_multiply.h

# Full android script
android-all: android-clean android-build header android-relocate

# Full script
all: android-all ios-all
