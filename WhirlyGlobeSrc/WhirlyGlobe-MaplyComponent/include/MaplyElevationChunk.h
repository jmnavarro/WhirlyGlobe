/*
 *  MaplyElevationSource.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by @jmnavarro on 6/13/15.
 *  Copyright 2011-2015 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
#import "MaplyComponentObject.h"
#import "MaplyCoordinateSystem.h"
#import "MaplyTileSource.h"
#import "Drawable.h"

@class WhirlyKitElevationChunk;


/** @brief The Maply Elevation Chunk is the abstract type to hold
    elevations for a single tile.
    @details The specific way to store the elevation depends on the child class
    @details Defines a contract to convert the elevation data into a drawable object
  */
@interface MaplyElevationChunk : NSObject

- (WhirlyKit::BasicDrawable *)elevDrawable;
- (WhirlyKitElevationChunk *)whirlyKitType;

@end


/** @brief The Maply Elevation Chunk holds elevations for a single tile.
    @details This object holds elevaiton data for a single tile.
    Each tile overlaps the the eastern and northern neighbors by one
    cell.  Why?  Because we're generating triangles with these and
    they're independent.  Draw a picture, it'll make sense.
    @details Data values are currently onl 32 bit floating point.
    There may be a type parameter in the future.
  */
@interface MaplyElevationGridChunk : MaplyElevationChunk

/** @brief Initialize with the data and size.
    @details This initializer takes an NSData object with the given number of
    samples.  Don't forget to add an extra one along the eastern and
    northern edges to match up with those tiles.  You still need to
    pass in as many samples as you're saying you are.  So if you say
    11 x 11, then there need to be 121 floats in the NSData object.
    @param data The NSData full of float (32 bit) samples.
    @param numX Number of samples in X.
    @param numY Number of samples in Y.
  */
- (id)initWithData:(NSData *)data numX:(unsigned int)numX numY:(unsigned int)numY;

/// @brief Number of samples in X
@property (nonatomic,readonly) unsigned int numX;
/// @brief Number of samples in Y
@property (nonatomic,readonly)unsigned int numY;

/// This is the data.  Elevations are floats (32 bit) in meters.
@property (nonatomic,readonly,strong) NSData *data;

@end



/** @brief The Maply Elevation Cesium Chunk holds elevation data retrieved from a Cesium server for a single tile.
    @see http://cesiumjs.org/data-and-assets/terrain/formats/quantized-mesh-1.0.html
  */
@interface MaplyElevationCesiumChunk : MaplyElevationChunk

- (id)initWithData:(NSData *)data;

@end
