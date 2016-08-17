#
# Be sure to run `pod lib lint WhirlyGlobe.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "WhirlyGlobe"
  s.version          = "2.4.1"
  s.summary          = "WhirlyGlobe-Maply: Geospatial visualization for iOS and Android."
  s.description      = <<-DESC
                        WhirlyGlobe-Maply is a high performance geospatial display toolkit for iOS and Android.
                        The iOS version supports big, complex apps like Dark Sky and National Geographic World Atlas,
                        among others.  Even so, it's easy to get started on your own project.
                       DESC
  s.homepage         = "https://github.com/mousebird/WhirlyGlobe"
  s.screenshots     = "http://mousebird.github.io/WhirlyGlobe/images/carousel/home/mapandglobe.jpg", "http://mousebird.github.io/WhirlyGlobe/images/carousel/home/mtrainier.jpg"
  s.license          = 'Apache 2.0'
  s.author           = { "Steve Gifford" => "contact@mousebirdconsulting.com" }
  s.social_media_url = 'https://twitter.com/@mousebirdc'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source = { :http => "https://s3-us-west-1.amazonaws.com/whirlyglobemaplydistribution/iOS_daily_builds/WhirlyGlobe-Maply_Nightly_latestzzzzzz.zip" }
  s.frameworks = 'CoreLocation'
  s.vendored_frameworks = 'WhirlyGlobeMaplyComponent.framework'
  s.xcconfig = {
      #'USER_HEADER_SEARCH_PATHS' => '$(inherited) ${PODS_ROOT}/WhirlyGlobe/WhirlyGlobeMaplyComponent.framework/Headers/',
      #'LIBRARY_SEARCH_PATHS' => '$(SRCROOT)/Pods/**'
  }
  s.library = 'z', 'c++', 'xml2', 'sqlite3'

end
