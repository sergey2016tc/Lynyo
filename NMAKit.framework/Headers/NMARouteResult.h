/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

 /**
 * \brief Implicit routing options that may be violated by routing calculation operations.
 *
 * \note Violations which depend on traffic data (e.g. BlockedRoad) will only be returned if
 * the traffic feature is available.
 */
// The violatedOptions value returned from NMARouter will be an OR
// combination of NMARoutingOption and NMARoutingViolatedOption values. Thus the
// NMARoutingViolatedOption values offset from a larger value to leave room
// for NMARoutingOption values to grow in the future.
typedef NS_OPTIONS(NSInteger, NMARoutingViolatedOption) {
    /** The returned route does not violate any options */
    NMARoutingViolatedOptionNone                          = 0,
    /** The route passes through a blocked road (e.g. due to construction or a traffic accident) */
    NMARoutingViolatedOptionBlockedRoad                   = 1 << 12,
    /** The route passes through a road with a time-based turn restriction */
    NMARoutingViolatedOptionTurnRestriction               = 1 << 13,
    /** The route's start direction is not as requested */
    NMARoutingViolatedOptionStartDirection                = 1 << 14
};


/**
 * \class NMARouteResult NMARouteResult.h "NMARouteResult.h"
 *
 * Contains the result for a routing query.
 */
@interface NMARouteResult : NSObject

/**
 * An NSArray of NMARoute objects representing alternate route
 * solutions, or nil if route calculation failed. The route at
 * index 0 is the best result found. The number of routes in
 * the array will be less than or equal to the resultCount
 * property specified in the %NMARoutingMode used for the route
 * request. Only one result will be returned for routes with more
 * than two waypoints. (Note that %NMATransitRoute objects are returned
 * for public transport routing only. Applications must show
 * sourceAttribution info of NMATransitRoute if it is
 * available).
 */
@property (nonatomic, readonly) NSArray *routes;

/**
* NSArray of NSNumber objects, one per route calculated,
* representing which options (if any) were violated for the
* corresponding route. The NSNumber objects should be converted to
* NSUInteger before checking. The value will be an OR combination of
* NMARoutingOption and %NMARoutingViolatedOption values, or
* NMARoutingViolatedOptionNone if no options were violated. If route calculation
* failed, the array will contain a single object containing all the routing
* options (if any).
*/
@property (nonatomic, readonly) NSArray *violatedOptions;

@end

/** @}  */
