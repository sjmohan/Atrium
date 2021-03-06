<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _atrium_intranet_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'atrium',
    'attribute' => 'global',
    'value' => 'blocks',
    'description' => 'Sitewide blocks',
    'sitewide' => array(
      '0' => '1',
    ),
    'block' => array(
      'admin_message_admin_message' => array(
        'module' => 'admin_message',
        'delta' => 'admin_message',
        'weight' => 20,
        'region' => 'console',
        'status' => '0',
        'label' => 'Admin messages',
        'type' => 'context_ui',
      ),
      'views_atrium_groups-block_1' => array(
        'module' => 'views',
        'delta' => 'atrium_groups-block_1',
        'weight' => 21,
        'region' => 'header',
        'status' => '0',
        'label' => 'atrium_groups: Block',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'atrium',
    'attribute' => 'section',
    'value' => 'admin',
    'description' => '',
    'node' => array(
      '0' => 'admin_message',
    ),
    'path' => array(
      '0' => 'atrium',
    ),
    'views' => array(
      '0' => 'atrium_admin_messages',
    ),
  );
  $items[] = array(
    'namespace' => 'spaces',
    'attribute' => 'feature',
    'value' => 'groups',
    'menu' => 'groups',
    'views' => array(
      '0' => 'atrium_groups',
    ),
    'theme_section' => array(
      'title' => 'Groups',
      'subtitle' => '',
      'class' => '',
    ),
    'block' => array(),
  );
  $items[] = array(
    'namespace' => 'spaces',
    'attribute' => 'feature',
    'value' => 'members',
    'menu' => 'members',
    'views' => array(
      '0' => 'atrium_members',
    ),
    'theme_section' => array(
      'title' => 'Members',
      'subtitle' => '',
      'class' => '',
    ),
    'block' => array(
      'views_-exp-atrium_members-default' => array(
        'module' => 'views',
        'delta' => '-exp-atrium_members-default',
        'region' => 'right',
        'weight' => '-10',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_filter_default_formats().
 */
function _atrium_intranet_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML
  $formats[] = array(
    'name' => 'Full HTML',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'codefilter',
        'delta' => '0',
        'weight' => '0',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '0',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '1',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '10',
      ),
    ),
  );

  // Exported format: Messaging plain text
  $formats[] = array(
    'name' => 'Messaging plain text',
    'roles' => array(),
    'filters' => array(
      '0' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'messaging',
        'delta' => '1',
        'weight' => '-9',
      ),
    ),
  );

  // Exported format: Markdown
  $formats[] = array(
    'name' => 'Markdown',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'admin',
      '3' => 'manager',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'markdown',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'codefilter',
        'delta' => '0',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
    ),
  );

  return $formats;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _atrium_intranet_imagecache_default_presets() {
  $items = array(
    'fileview' => array(
      'presetname' => 'fileview',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_deprecated_scale',
          'data' => array(
            'fit' => 'inside',
            'width' => '60',
            'height' => '40',
          ),
        ),
      ),
    ),
    'user-m' => array(
      'presetname' => 'user-m',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '60',
            'height' => '60',
          ),
        ),
      ),
    ),
    'user-s' => array(
      'presetname' => 'user-s',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '30',
            'height' => '30',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _atrium_intranet_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Groups',
    'path' => 'groups',
    'weight' => '0',
    'description' => 'Provides a group management feature',
  );
  $items[] = array(
    'title' => 'Members',
    'path' => 'members',
    'weight' => '0',
    'description' => 'Provides a member directory and user management feature',
  );
  // Translatables
  array(
    t('Groups'),
    t('Members'),
    t('Provides a group management feature'),
    t('Provides a member directory and user management feature'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_spaces_presets().
 */
function _atrium_intranet_spaces_presets() {
  $presets = array();

  // Exported preset: atrium_intranet
  $presets[atrium_intranet] = array(
    'name' => 'Basic intranet',
    'description' => 'A basic intranet hub setup.',
    'type' => 'site',
    'preset' => array(
      'features' => array(
        'atrium_intranet' => 1,
        'atrium_dashboard' => 1,
      ),
      'settings' => array(
        'home' => 'home',
      ),
      'locked' => array(
        'features' => array(
          'atrium_intranet' => 1,
          'atrium_dashboard' => 1,
        ),
        'settings' => array(
          'home' => 0,
        ),
      ),
    ),
  );

  // Exported preset: atrium_og_private
  $presets[atrium_og_private] = array(
    'name' => 'Private group',
    'description' => 'A simple private group with a blog, document library and dashboard.',
    'type' => 'og',
    'preset' => array(
      'features' => array(
        'atrium_blog' => 1,
        'atrium_book' => 1,
        'atrium_calendar' => 0,
        'atrium_dashboard' => 1,
      ),
      'settings' => array(
        'home' => 'dashboard',
      ),
      'og' => array(
        'og_selective' => 3,
        'og_directory' => 0,
        'og_register' => 1,
        'og_private' => 1,
      ),
    ),
  );

  // Exported preset: atrium_og_public
  $presets[atrium_og_public] = array(
    'name' => 'Public group',
    'description' => 'A simple public group with a blog, document library and dashboard.',
    'type' => 'og',
    'preset' => array(
      'features' => array(
        'atrium_blog' => 2,
        'atrium_book' => 2,
        'atrium_calendar' => 0,
        'atrium_dashboard' => 2,
      ),
      'settings' => array(
        'home' => 'dashboard',
      ),
      'og' => array(
        'og_selective' => 0,
        'og_directory' => 1,
        'og_register' => 1,
        'og_private' => 0,
      ),
    ),
  );

  // Exported preset: atrium_user_simple
  $presets[atrium_user_simple] = array(
    'name' => 'Simple profile',
    'description' => 'A simple profile with a blog, calendar and dashboard.',
    'type' => 'user',
    'preset' => array(
      'features' => array(
        'atrium_blog' => '1',
        'atrium_book' => '0',
        'atrium_calendar' => '1',
        'atrium_dashboard' => '1',
      ),
      'settings' => array(
        'home' => 'profile',
      ),
      'locked' => array(
        'features' => array(
          'atrium_blog' => 1,
          'atrium_book' => 0,
          'atrium_calendar' => 1,
          'atrium_dashboard' => 1,
        ),
        'settings' => array(
          'home' => 1,
        ),
      ),
      'user' => array(),
    ),
  );

  return $presets;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _atrium_intranet_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages
  $permissions[] = array(
    'name' => 'access administration pages',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: add list of open ids
  $permissions[] = array(
    'name' => 'add list of open ids',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: admin menu
  $permissions[] = array(
    'name' => 'admin menu',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer atrium
  $permissions[] = array(
    'name' => 'administer atrium',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer comments
  $permissions[] = array(
    'name' => 'administer comments',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: administer filters
  $permissions[] = array(
    'name' => 'administer filters',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer messaging
  $permissions[] = array(
    'name' => 'administer messaging',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer nodes
  $permissions[] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer notifications
  $permissions[] = array(
    'name' => 'administer notifications',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer permissions
  $permissions[] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer search
  $permissions[] = array(
    'name' => 'administer search',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer site configuration
  $permissions[] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer spaces
  $permissions[] = array(
    'name' => 'administer spaces',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer taxonomy
  $permissions[] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer users
  $permissions[] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: block users
  $permissions[] = array(
    'name' => 'block users',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: change own username
  $permissions[] = array(
    'name' => 'change own username',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: close admin messages
  $permissions[] = array(
    'name' => 'close admin messages',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: configure spaces features
  $permissions[] = array(
    'name' => 'configure spaces features',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: create group content
  $permissions[] = array(
    'name' => 'create group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: create users
  $permissions[] = array(
    'name' => 'create users',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: delete own group content
  $permissions[] = array(
    'name' => 'delete own group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: edit own group content
  $permissions[] = array(
    'name' => 'edit own group content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: post comments
  $permissions[] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: post comments without approval
  $permissions[] = array(
    'name' => 'post comments without approval',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: revert revisions
  $permissions[] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'admin',
      '1' => 'manager',
    ),
  );

  // Exported permission: search content
  $permissions[] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: select different theme
  $permissions[] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: skip notifications
  $permissions[] = array(
    'name' => 'skip notifications',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: subscribe other users
  $permissions[] = array(
    'name' => 'subscribe other users',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: subscribe to content
  $permissions[] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: upload files
  $permissions[] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: upload files to comments
  $permissions[] = array(
    'name' => 'upload files to comments',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: use advanced search
  $permissions[] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view files uploaded to comments
  $permissions[] = array(
    'name' => 'view files uploaded to comments',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view imagecache fileview
  $permissions[] = array(
    'name' => 'view imagecache fileview',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view imagecache spaces-logo
  $permissions[] = array(
    'name' => 'view imagecache spaces-logo',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view imagecache user-m
  $permissions[] = array(
    'name' => 'view imagecache user-m',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view imagecache user-s
  $permissions[] = array(
    'name' => 'view imagecache user-s',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'admin',
      '2' => 'manager',
    ),
  );

  return $permissions;
}
