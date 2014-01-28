/*
 *  VectorObject.h
 *  WhirlyGlobeLib
 *
 *  Created by Steve Gifford on 7/17/11.
 *  Copyright 2011-2013 mousebird consulting
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

#import "VectorData.h"

namespace WhirlyKit
{

/** @brief The C++ object we use to wrap a group of vectors and consolidate the various methods for manipulating vectors.
    @details The VectorObject stores a list of reference counted VectorShape objects.
  */
class VectorObject
{
public:
    /// @brief Construct empty
    VectorObject();
    
    /// @brief Add objects form the given GeoJSON string.
    /// @param json The GeoJSON data as a std::string
    /// @return True on success, false on failure.
    bool fromGeoJSON(const std::string &json);

    /// @brief Assemblies are just concattenated JSON
    bool fromGeoJSONAssembly(const std::string &json);
    
public:
    ShapeSet shapes;
};

}
