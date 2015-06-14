/*
 *  MaplyElevationSource.m
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
 *  Unless required by applicable law or agreed to sin writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import "MaplyElevationChunk.h"
#import "WhirlyVector.h"
#import "ElevationChunk.h"



using namespace WhirlyKit;

@implementation MaplyElevationChunk

- (BasicDrawable *)elevDrawable
{
    NSAssert(NO, @"elevDrawable is intended to be overriden");
	return nil;
}

- (WhirlyKitElevationChunk *)whirlyKitType
{
    NSAssert(NO, @"whirlyType is intended to be overriden");
	return nil;
}

@end



@implementation MaplyElevationGridChunk
{
    BOOL _isFloat;
}

- (id)initWithData:(NSData *)data numX:(unsigned int)numX numY:(unsigned int)numY
{
    self = [super init];
    if (!self)
        return nil;
    
    _numX = numX;
    _numY = numY;
    _data = data;

    _isFloat = ([_data length] == sizeof(float) * _numX * _numY);
    
    return self;
}

- (BasicDrawable *)elevDrawable
{
    // dumb implementation
    // Maybe it should be a grid made of triangles?

	const float *buffer = (const float *) [_data bytes];

    BasicDrawable *drawable = new BasicDrawable("Elevation");
    drawable->setType(GL_POINTS);

    for (int x = 0; x < _numX; ++x)
    {
        for (int y = 0; y < _numY; ++y)
        {
            //JM normalize elevation??
            Point3f pt = Point3f(x, y, buffer[x * y]);
            drawable->addPoint(pt);
        }
    }

    return drawable;
}

- (WhirlyKitElevationChunk *)whirlyKitType
{
    WhirlyKitElevationChunk *wkChunk;

    if (_isFloat)
    {
        wkChunk = [[WhirlyKitElevationChunk alloc] initWithFloatData:_data sizeX:_numX sizeY:_numY];
    }
    else
    {
        wkChunk = [[WhirlyKitElevationChunk alloc] initWithShortData:_data sizeX:_numX sizeY:_numY];
    }

	return wkChunk;
}

@end
