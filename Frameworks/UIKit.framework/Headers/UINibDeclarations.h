#if USE_UIKIT_PUBLIC_HEADERS || !__has_include(<UIKitCore/UINibDeclarations.h>)
//
//  UINibDeclarations.h
//  UIKit
//
//  Copyright (c) 2005-2017 Apple Inc. All rights reserved.
//

#ifndef IBOutlet
#define IBOutlet
#endif

#ifndef IBOutletCollection
#define IBOutletCollection(ClassName)
#endif

#ifndef IBAction
#define IBAction void
#endif

#ifndef IBInspectable
#define IBInspectable
#endif

#ifndef IB_DESIGNABLE
#define IB_DESIGNABLE
#endif


#else
#import <UIKitCore/UINibDeclarations.h>
#endif
