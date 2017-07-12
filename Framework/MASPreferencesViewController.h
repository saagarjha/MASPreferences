//
// Any controller providing preference pane view must support this protocol
//

#import <AppKit/AppKit.h>

// NSUserInterfaceItemIdentifier is only definined in macOS 10.13+. We need
// to define it ourselves if we're on macOS Sierra or lower.
#if !defined(MAC_OS_X_VERSION_10_13)
typedef NSString * NSUserInterfaceItemIdentifier NS_EXTENSIBLE_STRING_ENUM;
#endif

NS_ASSUME_NONNULL_BEGIN

/*!
 * Requirements for the Preferences panel
 */
@protocol MASPreferencesViewController <NSObject>

/*!
 * Unique identifier of the Panel represented by the view controller.
 */
@property (nonatomic, readonly, nullable) NSUserInterfaceItemIdentifier identifier;

/*!
 * Toolbar icon for the Panel represented by the view controller.
 */
@property (nonatomic, readonly, nullable) NSImage *toolbarItemImage;

/*!
 * Toolbar item label for the Panel represented by the view controller.
 *
 * This label may be used as a Preferences window title.
 */
@property (nonatomic, readonly, nullable) NSString *toolbarItemLabel;

@optional

/*!
 * Called when selection goes to the Panel represented by the view controller.
 */
- (void)viewWillAppear;

/*!
 * Called when selection goes to another Panel.
 */
- (void)viewDidDisappear;

/*!
 * Returns initial control in the key view loop.
 *
 * @return The view to focus on automatically when the panel is open.
 */
- (__kindof NSView *)initialKeyView;

/*!
 * The flag used to detect if the Prerences window can be resized horizontally.
 */
@property (nonatomic, readonly) BOOL hasResizableWidth;

/*!
 * The flag used to detect if the Prerences window can be resized vertically.
 */
@property (nonatomic, readonly) BOOL hasResizableHeight;

@end

NS_ASSUME_NONNULL_END
