/*
 *  MaplyElevationCesiumChunk.h
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
#import "MaplyElevationChunk.h"
#import "VectorData.h"
#import <vector>


using namespace std;
using namespace WhirlyKit;


/** @brief The Maply Elevation Cesium Chunk holds elevation data retrieved from a Cesium server for a single tile.
    @see http://cesiumjs.org/data-and-assets/terrain/formats/quantized-mesh-1.0.html
  */
@interface MaplyElevationCesiumChunk : MaplyElevationChunk

- (id)initWithData:(NSData *)data;

@property (nonatomic, readonly) VectorTrianglesRef mesh;

//TODO needed?
@property (nonatomic, readonly) vector<unsigned int> westVertices;
@property (nonatomic, readonly) vector<unsigned int> southVertices;
@property (nonatomic, readonly) vector<unsigned int> eastVertices;
@property (nonatomic, readonly) vector<unsigned int> northVertices;

@end


void testCesiumElevationChunk();