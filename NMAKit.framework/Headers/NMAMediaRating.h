/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMedia.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */


/**
 * \class NMAMediaRating NMAMediaRating.h "NMAMediaRating.h"
 *
 * Represents rating content about a NMAPlace.
 *
 * \sa NMAMediaImage
 * \sa NMAMediaReview
 * \sa NMAMediaEditorial
 */
@interface NMAMediaRating : NMAMedia

/**
 * The average rating for this NMAPlace.
 */
@property (nonatomic, readonly) double average;

/**
 * The number of individual votes that users provide for rating this
 * NMAPlace.
 */
@property (nonatomic, readonly) NSUInteger count;

@end

/** @} */
