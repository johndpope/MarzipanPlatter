#if USE_UIKIT_PUBLIC_HEADERS || !__has_include(<UIKitCore/UIInteraction.h>)
//
//  UIInteraction.h
//  UIKit
//
//  Copyright © 2017 Apple Inc. All rights reserved.
//

#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0), watchos(5.0)) API_UNAVAILABLE(tvos) @protocol UIInteraction <NSObject>

@property (nonatomic, nullable, weak, readonly) __kindof UIView *view;

- (void)willMoveToView:(nullable UIView *)view;
- (void)didMoveToView:(nullable UIView *)view;

@end


@interface UIView (Interactions)

- (void)addInteraction:(id<UIInteraction>)interaction API_AVAILABLE(ios(11.0), watchos(5.0)) API_UNAVAILABLE(tvos);
- (void)removeInteraction:(id<UIInteraction>)interaction API_AVAILABLE(ios(11.0), watchos(5.0)) API_UNAVAILABLE(tvos);

@property (nonatomic, copy) NSArray<id<UIInteraction>> *interactions API_AVAILABLE(ios(11.0), watchos(5.0)) API_UNAVAILABLE(tvos);

@end

NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIInteraction.h>
#endif
