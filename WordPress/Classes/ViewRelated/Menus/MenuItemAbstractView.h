#import <UIKit/UIKit.h>

extern CGFloat const MenuItemsStackableViewDefaultHeight;

@protocol MenuItemDrawingViewDelegate <NSObject>
- (void)drawingViewDrawRect:(CGRect)rect;
@end

@interface MenuItemDrawingView : UIView

@end

@protocol MenuItemAbstractViewDelegate;

@interface MenuItemAbstractView : UIView <MenuItemDrawingViewDelegate>

@property (nonatomic, weak) id <MenuItemAbstractViewDelegate> delegate;

/**
 Content view in which most of the drawing and MenuItem content is setup in.
 */
@property (nonatomic, strong, readonly) MenuItemDrawingView *contentView;

/**
 The highlighted state.
 */
@property (nonatomic, assign) BOOL highlighted;

/**
 Toggles the drawing as a placeholder (dashed lines while ordering).
 */
@property (nonatomic, assign) BOOL isPlaceholder;

/**
 Toggles the drawing of the line separator.
 */
@property (nonatomic, assign) BOOL drawsLineSeparator;

/**
 The visual indentation for parent/child relationships.
 */
@property (nonatomic, assign) NSInteger indentationLevel;

/**
 The primary stackView.
 */
@property (nonatomic, strong, readonly) UIStackView *stackView;

/**
 The primary textLabel.
 */
@property (nonatomic, strong, readonly) UILabel *textLabel;

/**
 The primary icon imageView.
 */
@property (nonatomic, strong, readonly) UIImageView *iconView;

/**
 Accessory stackView used for secondary views on the right side.
 */
@property (nonatomic, strong, readonly) UIStackView *accessoryStackView;

/**
 Tracker for a stackableView appearing before this view in a stack.
*/
@property (nonatomic, weak) MenuItemAbstractView *previous;

/**
 Tracker for a stackableView appearing after this view in a stack.
 */
@property (nonatomic, weak) MenuItemAbstractView *next;

/**
 Add an accessory button to the accessoryStackView.
 */
- (void)addAccessoryButton:(UIButton *)button;

/**
 Add an accessory button with an image icon to the accessoryStackView.
 */
- (UIButton *)addAccessoryButtonIconViewWithImage:(UIImage *)image;

/**
 The backgroundColor the contentView should use for any highlighted state changes.
 */
- (UIColor *)contentViewBackgroundColor;

/**
 TextColor of the label during any any highlighted state changes.
 */
- (UIColor *)textLabelColor;

/**
 TintColor of the icon during any any highlighted state changes.
 */
- (UIColor *)iconTintColor;

@end

@protocol MenuItemAbstractViewDelegate <NSObject>

/**
 The highlighted state changed for the stackableView.
 */
- (void)itemView:(MenuItemAbstractView *)itemView highlighted:(BOOL)highlighted;
@end