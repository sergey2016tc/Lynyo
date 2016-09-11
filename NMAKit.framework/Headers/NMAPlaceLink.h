/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMALink.h"

@class NMACategory;
@class NMAPlaceRequest;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 *
 * \class NMAPlaceLink NMAPlaceLink.h "NMAPlaceLink.h"
 *
 * Represents metadata about a place, this object is usually returned as a response to places search.
 *
 * \note To retrieve the actual NMAPlace object use the {@link detailsRequest} property.
 *
 */
@interface NMAPlaceLink : NMALink

/**
 * The %NMAGeoCoordinates representing the geographical position
 * of the NMAPlace.
 */
@property (nonatomic, readonly, strong) NMAGeoCoordinates *position;

/**
 * The distance to the NMAPlace, in meters.
 *
 * \note Distance information for a place is optional. Attempts to read this
 * property could return be zero.
 */
@property (nonatomic, readonly) NSInteger distance;

/**
 * The average rating for the NMAPlace if available, otherwise
 *        -1.0 to indicate the value is not available.
 */
@property (nonatomic, readonly) double averageRating;

/**
 * The %NMACategory to the primary category for the NMAPlace.
 */
@property (nonatomic, readonly, strong) NMACategory *category;

/**
 * The %NSString description of the vicinity surrounding the
 * NMAPlaceLink.
 * <p>
 * Typically, this property is derived from the address, but could also
 * contain any other description that helps an application user understand
 * where the place is located.</p>
 */
@property (nonatomic, readonly, strong) NSString *vicinityDescription;

/**
 * The enclosing %NMAGeoBoundingBox describing a range of coordinates
 * that correspond to the NMAPlace. Typically, bounding boxes are
 * associated with places such as cities and countries.
 *
 * \note Bounding box information for a place is optional. Attempts to read
 * this property could return nil.
 */
@property (nonatomic, readonly, strong) NMAGeoBoundingBox *boundingBox;

/**
 * Indicates whether this search result is sponsored.
 * <p>
 * Applications should provide some visual differentiation between sponsored
 * search results and regular search results.</p>
 *
 * \note Sponsorship is an optional attribute for a place.
 */
@property (nonatomic, readonly) BOOL isSponsored;

/**
 * Gets the request to retrieve the NMAPlace details.
 * Attempts to read this property could return nil.
 */
- (NMAPlaceRequest *)detailsRequest;

/*!
 * \brief Get reference identifiers for a specific source. For example, a place
 * can have a reference to an extruded building object in the map. The
 * reference identifiers can be retrieved by calling this method with source
 * NMAPlacesSourceBuilding.
 *
 * Index 0 is the primary reference identifier for the place.
 *
 * \note A reference identifier will not be returned if it has not been queried
 * with the \link NMARequest::addSource:\endlink function.
 *
 * \param source %NSString specifying the source
 * \return An NSArray of reference identifiers. Return nil if reference
 * identifier does not exist.
 */
- (NSArray *)referenceIdentifiersForSource:(NSString *)source;

#pragma mark - DEPRECATED

/**
 * Gets the %NSString representation of the link URL.
 * </p>
 * <p>
 * This URL may be used to perform an HTTP GET request to the HERE Places REST service
 * to retrieve the full metadata of the linked resources for online.
 *
 * Use the request methods in dervied classes for offline. See also
 * NMAPlaceLink#detailsRequest and NMADiscoveryLink#request.
 * </p>
 * <p>
 * The request may return a HTML or JSON response. If url contains "places.hybrid.api.here.com",
 * it will return a JSON response as specified at http://developer.here.com/places
 * If URL contains other domains, it will most likely return a HTML response.
 *
 * \deprecated: This property is deprecated since release 3.2. Please use NMAPlaceLink#detailsRequest
 * and NMADiscoveryLink#request.
 */
@property (nonatomic, strong, readonly) NSString *url DEPRECATED_ATTRIBUTE;

@end
/** @} */
