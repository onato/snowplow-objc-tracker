//
//  SPSubjectConfiguration.h
//  Snowplow
//
//  Copyright (c) 2013-2022 Snowplow Analytics Ltd. All rights reserved.
//
//  This program is licensed to you under the Apache License Version 2.0,
//  and you may not use this file except in compliance with the Apache License
//  Version 2.0. You may obtain a copy of the Apache License Version 2.0 at
//  http://www.apache.org/licenses/LICENSE-2.0.
//
//  Unless required by applicable law or agreed to in writing,
//  software distributed under the Apache License Version 2.0 is distributed on
//  an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
//  express or implied. See the Apache License Version 2.0 for the specific
//  language governing permissions and limitations there under.
//
//  Authors: Alex Benini
//  License: Apache License Version 2.0
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "SPConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

@interface SPSize : NSObject <NSCoding>

@property (readonly) NSInteger width;
@property (readonly) NSInteger height;

- initWithWidth:(NSInteger)width height:(NSInteger)height;

@end


NS_SWIFT_NAME(SubjectConfigurationProtocol)
@protocol SPSubjectConfigurationProtocol

/**
 * The custom UserID.
 */
@property (nullable) NSString *userId;
/**
 * The network UserID.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) NSString *networkUserId;
/**
 * The domain UserID.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) NSString *domainUserId;
/**
 * The user-agent.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) NSString *useragent;
/**
 * The IP address.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) NSString *ipAddress;

/**
 * The current timezone.
 */
@property (nullable) NSString *timezone;
/**
 * The language set in the device.
 */
@property (nullable) NSString *language;

/**
 * The screen resolution.
 */
@property (nullable) SPSize *screenResolution;
/**
 * The screen viewport.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) SPSize *screenViewPort;
/**
 * The color depth.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
@property (nullable) NSNumber *colorDepth;

// MARK: - GeoLocation

/*!
 Latitude value for the geolocation context.
 */
@property (nullable) NSNumber *geoLatitude;

/*!
 Longitude value for the geo context.
 */
@property (nullable) NSNumber *geoLongitude;

/*!
 LatitudeLongitudeAccuracy value for the geolocation context.
 */
@property (nullable) NSNumber *geoLatitudeLongitudeAccuracy;

/*!
 Altitude value for the geolocation context.
 */
@property (nullable) NSNumber *geoAltitude;

/*!
 AltitudeAccuracy value for the geolocation context.
 */
@property (nullable) NSNumber *geoAltitudeAccuracy;

/*!
 Bearing value for the geolocation context.
 */
@property (nullable) NSNumber *geoBearing;

/*!
 Speed value for the geolocation context.
 */
@property (nullable) NSNumber *geoSpeed;

/*!
 Timestamp value for the geolocation context.
 */
@property (nullable) NSNumber *geoTimestamp;

@end

/**
 * This class represents the configuration of the subject.
 * The SubjectConfiguration can be used to setup the tracker with the basic information about the
 * user and the app which will be attached on all the events as contexts.
 * The contexts to track can be enabled in the `TrackerConfiguration` class.
 */
NS_SWIFT_NAME(SubjectConfiguration)
@interface SPSubjectConfiguration : SPConfiguration <SPSubjectConfigurationProtocol>

/**
 * The custom UserID.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, userId)
/**
 * The network UserID.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, networkUserId)
/**
 * The domain UserID.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, domainUserId)
/**
 * The user-agent.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, useragent)
/**
 * The IP address.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, ipAddress)
/**
 * The current timezone.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, timezone)
/**
 * The language set in the device.
 */
SP_BUILDER_DECLARE_NULLABLE(NSString *, language)
/**
 * The screen resolution.
 */
SP_BUILDER_DECLARE_NULLABLE(SPSize *, screenResolution)
/**
 * The screen viewport.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(SPSize *, screenViewPort)
/**
 * The color depth.
 * Note: It's not generated by the tracker, it needs to be filled by the developer when instrumenting the tracker.
 */
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, colorDepth)

// GeoLocation builders

/// Latitude value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoLatitude)

/// Longitude value for the geo context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoLongitude)

/// LatitudeLongitudeAccuracy value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoLatitudeLongitudeAccuracy)

/// Altitude value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoAltitude)

/// AltitudeAccuracy value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoAltitudeAccuracy)

/// Bearing value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoBearing)

/// Speed value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoSpeed)

/// Timestamp value for the geolocation context.
SP_BUILDER_DECLARE_NULLABLE(NSNumber *, geoTimestamp)

@end

NS_ASSUME_NONNULL_END
