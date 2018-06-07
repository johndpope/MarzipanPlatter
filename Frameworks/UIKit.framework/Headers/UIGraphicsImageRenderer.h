#if USE_UIKIT_PUBLIC_HEADERS || !__has_include(<UIKitCore/UIGraphicsImageRenderer.h>)
//
//  UIGraphicsImageRenderer.h
//  UIKit
//
//  Copyright (c) 2016-2017 Apple Inc. All rights reserved.
//

#import <UIKit/UIGraphicsRenderer.h>
#import <UIKit/UIImage.h>

NS_ASSUME_NONNULL_BEGIN

@class UIGraphicsImageRendererContext;

typedef void (^UIGraphicsImageDrawingActions)(UIGraphicsImageRendererContext *rendererContext) NS_AVAILABLE_IOS(10_0);

typedef NS_ENUM(NSInteger, UIGraphicsImageRendererFormatRange) {
    UIGraphicsImageRendererFormatRangeUnspecified = -1,
    UIGraphicsImageRendererFormatRangeAutomatic = 0,
    UIGraphicsImageRendererFormatRangeExtended,
    UIGraphicsImageRendererFormatRangeStandard
} NS_ENUM_AVAILABLE_IOS(12_0);

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsImageRendererFormat : UIGraphicsRendererFormat

@property (nonatomic) CGFloat scale; // display scale of the context. The preferredFormat uses the scale most appropriate for the main screen's current configuration.
@property (nonatomic) BOOL opaque; // indicates the bitmap context will draw fully opaque. The preferredFormat sets this to NO.
@property (nonatomic) BOOL prefersExtendedRange NS_DEPRECATED_IOS(10_0, 12_0, "Use the preferredRange property instead"); // indicates the bitmap context should draw into a context capable of rendering extended color images. The preferredFormat sets this according to the main screen's current configuration.

@property (nonatomic) UIGraphicsImageRendererFormatRange preferredRange NS_AVAILABLE_IOS(12_0);

// Returns a format optimized for the specified trait collection, taking into account properties such as displayScale and displayGamut.
// Traits that are not specified will be ignored, with their corresponding format properties defaulting to the values in preferredFormat.
+ (instancetype)formatForTraitCollection:(UITraitCollection *)traitCollection NS_AVAILABLE_IOS(11_0);
@end

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsImageRendererContext : UIGraphicsRendererContext
@property (nonatomic, readonly) UIImage *currentImage; // Returns a UIImage representing the current state of the renderer's CGContext
@end

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsImageRenderer : UIGraphicsRenderer
- (instancetype)initWithSize:(CGSize)size;
- (instancetype)initWithSize:(CGSize)size format:(UIGraphicsImageRendererFormat *)format NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithBounds:(CGRect)bounds format:(UIGraphicsImageRendererFormat *)format NS_DESIGNATED_INITIALIZER;

// Returns a UIImage rendered with the contents of the CGContext after the imageRenderBlock executes.
// If the options provided to the renderer contain a rect with a zero width or height size, this will return an empty UIImage.
- (UIImage *)imageWithActions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;

// These return compressed image data with the contents of the image drawn in the renderer block.
- (NSData *)PNGDataWithActions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;
- (NSData *)JPEGDataWithCompressionQuality:(CGFloat)compressionQuality actions:(NS_NOESCAPE UIGraphicsImageDrawingActions)actions;
@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIGraphicsImageRenderer.h>
#endif
