// Copyright (c) 2014-present, Facebook, Inc. All rights reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "TargetConditionals.h"

#if !TARGET_OS_TV

#import <Foundation/Foundation.h>
@protocol FBSDKValidatable;
@protocol FBSDKContextDialogDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
  The protocol sdk dialogs must conform to and implement all the following methods.
 */
NS_SWIFT_NAME(DialogProtocol)
@protocol FBSDKDialog <NSObject>
/**
  The receiver's delegate or nil if it doesn't have a delegate.
 */
@property (nonatomic, weak, nullable) id<FBSDKContextDialogDelegate> delegate;

/**
  The content object used to create the specific dialog
 */
@property (nonatomic, copy, nullable) id<FBSDKValidatable> dialogContent;

/**
  Begins to show the specfic dialog
 @return YES if the receiver was able to show the dialog, otherwise NO.
 */
- (BOOL)show;

/**
  Validates the content for the dialog
 @param errorRef If an error occurs, upon return contains an NSError object that describes the problem.
 @return YES if the content is valid, otherwise NO.
 */
- (BOOL)validateWithError:(NSError *__autoreleasing *)errorRef;
@end


/**
  A protocol that a content object must conform to be used in a Gaming Services dialog
 */
NS_SWIFT_NAME(ValidatableProtocol)
@protocol FBSDKValidatable <NSObject>

- (BOOL)validateWithError:(NSError *__autoreleasing *)errorRef;
@end

NS_ASSUME_NONNULL_END
#endif
