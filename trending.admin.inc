<?php

/**
 * Form builder.
 * Trending settings form
 */
function trending_settings_form($form, &$form_state)
{

    // Variable determing a time frame to treat an previous visitor as a new one
    $form['identity_expiry_period'] = array(
        '#type' => 'textfield',
        '#title' => t('Identity Expiry Period'),
        '#description' => t('Enter expiry period for users global session in days'),
        '#default_value' => variable_get('identity_expiry_period',''),
    );
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
    );
    return $form;
}

function trending_settings_form_validate($form, &$form_state){
    if(isset($form_state['values']['identity_expiry_period'])){
        if(!is_numeric($form_state['values']['identity_expiry_period'])){
            form_set_error('identity_expiry_period',t('Enter numeric character for expiry period'));
        }
    }
}

function trending_settings_form_submit($form, &$form_state){
    variable_set('identity_expiry_period',$form_state['values']['identity_expiry_period']);
    drupal_set_message(t('Settings saved successfully.'));
}