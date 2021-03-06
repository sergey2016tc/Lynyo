/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMARoutingMode.h"

@class NMAGeoPosition;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * \brief The interface used to create a custom position source for NMAPositioningManager.
 *
 * Custom position data sources are used in conjunction with NMAPositioningManager to
 * provide position data to the application. To broadcast position updates, a source should
 * created and installed on the NMAPositioningManager using its dataSource property. When a
 * source has a new position available (or it determines the current postion is unknown 
 * because a position/GPS fix has been lost), it calls the dataSourceDidUpdatePosition:
 * method of NMAPositioningManager. The positioning manager then uses the currentPosition
 * method of the data source to retrieve the updated position.
 */
@protocol NMAPositionDataSource<NSObject>

@required

/*!
 * \brief Returns the latest position generated by the data source.
 *
 * This method is used by the NMAPositioningManager to retrieve position updates.
 *
 * \note If the the current postion is unknown because a position/GPS fix has been lost
 * this method should return nil.
 */
- (NMAGeoPosition *)currentPosition;

@optional

/*!
 * \brief Notifies the data source that position updates should start.
 *
 * This message is sent by the NMAPositioningManager to indicate to the data source
 * that positioning has been started. It will also be sent when a new data source
 * is installed on the positioning manager while it is active.
 */
- (void)start;

/*!
 * \brief Notifies the data source that position updates should stop.
 *
 * This message is sent by the NMAPositioningManager to indicate to the data source
 * that positioning has been stopped. It will also be sent to the data source when it
 * is removed from the positioning manager if positioning is active.
 */
- (void)stop;

/*!
 * Notifies the data source whether or not position updates should continue
 * when the app is sent to the background.
 *
 * \note The position data source in use must support background updates in order to
 * use positioning-dependent features such as navigation in the background.
 *
 * \sa NMANavigationManager::backgroundNavigationEnabled
 */
- (void)setBackgroundUpdatesEnabled:(BOOL)enabled;

/*!
 * Notifies the data source that NMANavigationManager has started a navigation session.
 *
 * The data source may wish to cache it's current settings and increase the frequency,
 * quality or accuracy of the position updates whilst navigation is active.
 */
- (void)navigationStartedWithTransportMode:(NMATransportMode)transportMode;

/*!
 * Notifies the data source that NMANavigationManager has stopped the navigation session.
 *
 * The data source may wish to reduce it's current settings (or restore previously cached
 * settings) in order to preserve battery life when navigation is not active.
 */
- (void)navigationStopped;

@end
/** @} */
