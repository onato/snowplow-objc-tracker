//
//  SPEmitterController.h
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
#import "SPEmitterConfiguration.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(EmitterController)
@protocol SPEmitterController <SPEmitterConfigurationProtocol>

/**
 * Number of events recorded in the EventStore.
 */
@property (nonatomic, readonly) NSInteger dbCount;

/**
 * Whether the emitter is currently sending events.
 */
@property (nonatomic, readonly) BOOL isSending;

- (void)flush;

/**
 * Pause emitting events.
 * Emitting events will be suspended until resumed again.
 * Suitable for low bandwidth situations.
 */
- (void)pause;

/**
 * Resume emitting events if previously paused.
 * The emitter will resume emitting events again.
 */
- (void)resume;

@end

NS_ASSUME_NONNULL_END
