# Creating the application components library
add_library(app_components
    app/Config.cpp
    core/Vector3D.cpp
    core/Quaternion.cpp
    core/Matrix.cpp
    # * Add other source files below ...
)

target_include_directories(app_components
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

# Linking with Eigen3
target_link_libraries(app_components
    PUBLIC
        Eigen3::Eigen
)

# Adding the main application executable
add_executable(cpp-app
    app/main.cpp
)

# Linking the application with the components library
target_link_libraries(cpp-app
    PRIVATE
        app_components
)